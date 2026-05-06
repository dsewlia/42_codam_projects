/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsewlia <dsewlia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 13:21:45 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/24 09:08:21 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Logger.hpp"
#include "Channel.hpp"
#include "defines.hpp"
#include <bits/stdc++.h>
#include <iomanip>
#include <regex>

void	Server::parsing(std::string &msg, int fd, Server &server)
{
	std::vector<std::string> splitCommands;
	std::string temp;
	
	int len = msg.length();
	int i;
	for (i = 0; i < len; i++)
	{
		temp.clear();
		while (i < len && msg[i] != '\n')
		{
			temp += msg[i];
			i++;
		}
		if (!temp.empty() && temp.back() == '\r')
			temp.pop_back();
		if (!temp.empty())
		{
			splitCommands.push_back(temp);
		}
	}
	len = splitCommands.size();
	for (i = 0; i < len; i++)
	{
		Message message(splitCommands[i], fd, server);
		message.executeCommand();
	}
}

std::set<std::string>	Server::_capabilities = {
	"multi-prefix",
	"server-time",
};

struct Clientstate* Server::getClientState(int fd)
{
	auto it = _clientStates.find(fd);
	if (it != _clientStates.end())
	{
		return (&it->second);
	}
	return (nullptr);
}

Server::Server(int port, const std::string &password)
	: _socket(port), _password(password), _pollFd() {
	_serverName = "ircserv";
	_setupPoll();
	_initDefaultChannel();
	Logger::get()->log("Server started on port " + std::to_string(port), INFO);
	}

Server::~Server() {
	Logger::get()->log("Server shutting down", INFO);
}

void Server::_initDefaultChannel(){
	std::string defaultChannel = "#general"; // Default channel name
	if (_channels.find(defaultChannel) == _channels.end()) {
		_channels[defaultChannel] = Channel();
		Logger::get()->log("Default channel " + defaultChannel + " created", INFO);
	}
}

//sets up polling to check multiple clients
void	Server::_setupPoll() {
	pollfd serverPoll = {};
	serverPoll.fd = _socket.getFd();
	serverPoll.events = POLLIN;
	_pollFd.push_back(serverPoll);

	pollfd stdinPoll = {};
	stdinPoll.fd = STDIN_FILENO;
	stdinPoll.events = POLLIN;
	_pollFd.push_back(stdinPoll);
}

void Server::run() {
	int clientFd;
	while (true) {
		int activity = poll(_pollFd.data(), _pollFd.size(), POLL_TIMEOUT);
		if (activity < 0) {
			Logger::get()->log(strerror(errno), ERROR);
			continue;
		}

		std::vector<int> fdsToRemove;
		std::vector<int> newClientFds;
		// Use index-based loop to avoid iterator invalidation
		for (size_t i = 0; i < _pollFd.size(); ++i) {
			pollfd &event = _pollFd[i];
			if (event.revents & POLLIN) {
				if (event.fd == STDIN_FILENO) {
					return ;
				} else if (event.fd == _socket.getFd()) {
						clientFd = _handleNewConection();
						newClientFds.push_back(clientFd);
				} else {
					try {
						_handleClientData(event.fd);
					} catch (const std::exception &e) {
						fdsToRemove.push_back(event.fd); // Mark for removal if an error occurs
					}
				}
			}
			// Also check for POLLHUP or POLLERR to remove dead connections
			if (event.revents & (POLLHUP | POLLERR)) { //see it is bitwise or orperators
				fdsToRemove.push_back(event.fd);
			}
		}
		
		for (int clientFd : newClientFds) {
			pollfd clientPoll = {};
			clientPoll.fd = clientFd;
			clientPoll.events = POLLIN;
			_pollFd.push_back(clientPoll);
		}

		// Remove disconnected clients after the loop
		for (int fd : fdsToRemove) {
			if (fd != STDIN_FILENO && fd != _socket.getFd()) {
				_disconnectClient(fd);
			}
		}
	}
}

int Server::_nickValidation(int clientFd, const std::string &newNick) {
	std::regex nickPattern("^[a-zA-Z][a-zA-Z0-9_]{0,14}$");
	if (newNick.empty() || newNick.length() > 15 || !std::regex_match(newNick, nickPattern)) {
		Logger::get()->log("Nickname " + newNick + " is invalid", WARNING);
		return 432; // Erroneous nickname
	}
	auto it = std::find_if(_clientStates.begin(), _clientStates.end(),
		[&newNick, clientFd](const auto &pair) {
			return pair.second.nickname == newNick && pair.first != clientFd;
		});
	if (it != _clientStates.end()) {
		Logger::get()->log("Nickname " + newNick + " is already in use by another client", WARNING);
		return 433; // Nickname is already in use
	}
	return 0;
}

std::string getServerHostname() {
	char hostname[256];
	if (gethostname(hostname, sizeof(hostname)) == 0) {
		return std::string(hostname);
	} else {
		return "ircserv";
	}
}

void	Server::_preParsing(const std::string &command, int clientFd) {
	std::string password;
	Clientstate &clientstate = _clientStates[clientFd];
	if (command.find("PASS") == 0) {
		std::istringstream iss(command);
		std::string passCmd;
		iss >> passCmd >> password;
		clientstate.user.setPassword(password);
		clientstate.hasPass = true;
	} else if (command.find("NICK") == 0) {
		std::istringstream iss(command);
		std::string nickCmd, nickname;
		iss >> nickCmd >> nickname;
		int isValid = _nickValidation(clientFd, nickname);
		if (isValid == 432) {
			_sendToClient(clientFd, ":" + _serverName + " 432 * " + nickname + " :Erroneous nickname\r\n");
		} else if (isValid == 433) {
			_sendToClient(clientFd, ":" + _serverName + " 433 * " + nickname + " :Nickname is already in use\r\n");
		} else {
			clientstate.nickname = nickname;
			clientstate.hasNick = true;
			_sendToClient(clientFd, ":" + nickname + " NICK :" + nickname + "\r\n");
		}
	} else if (command.find("USER") == 0) {
			std::istringstream iss(command);
		std::string username, hostname, servername, realname;
		iss >> username >> username >> hostname >> servername >> realname;
		clientstate.user.setUsername(username);
		clientstate.user.setHostname(hostname);
		clientstate.user.setRealname(realname);
		clientstate.hasUser = true;
	} else if (command.find("CAP") == 0) {
		_handleCap(clientFd, command);
	} else if (command.find("QUIT") == 0) {
		throw std::exception();
	}
	_registerUser(clientstate);
}

int Server::_handleNewConection() {
	User user;

	auto [clientFd, info] = _socket.sockAccept();
	_clientStates[clientFd].user = User::createUser(clientFd);
	return clientFd;
}

void	Server::_registerUser(Clientstate &clientstate) {
	int clientFd = clientstate.user.getFd();
	if (clientstate.hasNick && clientstate.hasUser && !clientstate.registered && clientstate.hasCapEnd == true && clientstate.hasCapLs == true && clientstate.hasPass == true) {
			if (clientstate.user.getPassword() != _password) {
				_sendToClient(clientFd, ":" + _serverName + " 464 " + clientstate.nickname + " :Password incorrect\r\n");
				Logger::get()->log("Password incorrect for server " + clientstate.nickname, WARNING);
				return ;
			}
			std::string nick = clientstate.nickname;
			std::string server = _serverName;
	
			_sendToClient(clientFd, ":" + server + " 001 " + nick + " :Welcome to the IRC Server\r\n");
			_sendToClient(clientFd, ":" + server + " 002 " + nick + " :Your host is " + server + ", running version 1.0\r\n");
			_sendToClient(clientFd, ":" + server + " 003 " + nick + " :This server was created today\r\n");
			_sendToClient(clientFd, ":" + server + " 004 " + nick + " " + server + " 1.0 o o\r\n");
			_sendToClient(clientFd, "NOTICE " + nick + " :Auto join general channel, use /window to move to another window\r\n");
	
			_handleJoin(clientFd, "#general", true);
			Logger::get()->log("New client connected: " + nick, INFO);
			clientstate.registered = true;
		}
}

void	Server::_handleCap(int clientFd, const std::string &cap) {
	std::istringstream iss(cap);
	std::string command;
	iss >> command >> command;
	if (command == "LS") {
		std::string version;
		iss >> version;
		_handleLs(clientFd, version);
	} else if (command == "REQ") {
		_handleReq(clientFd, cap.substr(iss.tellg())); 
	} else if (command == "END") {
		_clientStates[clientFd].hasCapEnd = true;
		return ;
	} else {
		_sendToClient(clientFd, ":" + _serverName + " 410 :Unknown CAP subcommand\r\n");
		return ;
	}
	return ;
}

void	Server::_handleLs(int clientFd, const std::string &version) {
	std::string capabilities = "";
	(void)version;
	for (const auto &cap : _capabilities) {
		capabilities += cap + " ";
	}
	if (!capabilities.empty()) {
		// Remove trailing space
		capabilities.pop_back();
		_sendToClient(clientFd, "CAP * LS :" + capabilities + "\r\n");
		_clientStates[clientFd].hasCapLs = true;
	}
}

void	Server::_handleReq(int clientFd, const std::string &req) {
	std::istringstream iss(req.substr(req.find(":") + 1)); // remove leading space
	std::string cap;
	std::string ackCap = "";
	std::string nakCap = "";
	
	while (iss >> cap) {
		if (_capabilities.find(cap) != _capabilities.end()) {
			ackCap += cap + " ";
		} else {
			nakCap += cap + " ";
		}
	}
	if (!nakCap.empty())
		_sendToClient(clientFd, "CAP * NAK :" + nakCap + "\r\n");
	_sendToClient(clientFd, "CAP * ACK :" + ackCap + "\r\n");
}


// reads data from existing user
void	Server::_handleClientData(int clientFd) {
	_clientStates[clientFd].lastActivity = time(NULL);
	char buffer[BUFFERS_SIZE];
	memset(buffer, 0, sizeof(buffer));// clear buffer
	int byteCount = recv(clientFd, buffer, sizeof(buffer) - 1, 0); // reads from socket

	if (byteCount <= 0) {
		if (byteCount == -1)
			Logger::get()->log(strerror(errno), ERROR);
		throw std::exception();
	}
	
	buffer[byteCount] = '\0'; // null-terminate the buffer
	if (DEBUG_MODE)
		std::cout << byteCount << " -> " << buffer << std::endl; // debug output

	_clientStates[clientFd].buffer.append(buffer, byteCount); // append received data to client's buffer

	size_t pos = 0;
	while ((pos = _clientStates[clientFd].buffer.find("\n")) != std::string::npos) {
		std::string command = _clientStates[clientFd].buffer.substr(0, pos);
		_clientStates[clientFd].buffer.erase(0, pos + 1);
		if (DEBUG_MODE)
			std::cout << command << std::endl;
		if (_clientStates[clientFd].registered	 == false) {
			_preParsing(command, clientFd);
		} else {
			parsing(command, clientFd, *this);
		}
		if (_clientStates[clientFd].buffer.empty())
			return;
	}
}

// removes client data and poll list and from all channels joined
void	Server::_disconnectClient(int clientFd) {
	_pollFd.erase(remove_if(_pollFd.begin(), _pollFd.end(),
	[clientFd](pollfd p) {return p.fd == clientFd;}), _pollFd.end());
	for (auto &[name, channel] : _channels)
		channel.removeMember(clientFd);
	_clientStates.erase(clientFd);
	close(clientFd);
}

void	Server::_handleJoin(int clientFd, const std::string &channelName, bool defaulJoin) {
	if (_channels.find(channelName) == _channels.end()) {
		_channels[channelName] = Channel();
		Logger::get()->log("Channel " + channelName + " created by " + _clientStates[clientFd].nickname, INFO);
	}
	Channel &chan = _channels[channelName];
	chan.addMember(clientFd);
	_clientStates[clientFd].joinedChannels.insert(channelName);

	Logger::get()->log("User " + _clientStates[clientFd].nickname + " joined channel " + channelName, INFO);
	std::ostringstream joinMessage;
	joinMessage << ":" << _clientStates[clientFd].nickname << "!" << _clientStates[clientFd].user.getUsername()
				<< "@" << _clientStates[clientFd].user.getHostname() << " JOIN :" << channelName << "\r\n";
	
	if (defaulJoin)
		_broadcastToChannel(channelName, joinMessage.str());
	else
		_broadcastToChannel(channelName, joinMessage.str(), clientFd);
}

void	Server::_sendToClient(int fd, const std::string &msg) {
	try{
		_socket.sockSend(fd, msg);
	} catch (const std::runtime_error &e) {
		std::cerr << "Error sending to client " << fd << ": " << e.what() << std::endl;
		Logger::get()->log("Error sending to client " + std::to_string(fd) + ": " + e.what(), ERROR);
		_disconnectClient(fd);
		return;
	}
}

void	Server::_broadcastToChannel(const std::string &channel, const std::string &msg, int excludeFd) {

	std::unordered_map<std::string, Channel>	&_allChannels = getChannels();
	const auto &it = _allChannels.find(channel);
	if (it == _allChannels.end())
		return ;
	Channel &ch = it->second;
	std::unordered_set<int> chFds = ch.getMembers();
	for (int member : chFds) {
		if (member != excludeFd && member > 1){
			_sendToClient(member, msg);
		}
	}
}

void	Server::addChannelToDatabase(Channel &newChannel)
{
	_channels[newChannel.getChannelName()] = newChannel;
};