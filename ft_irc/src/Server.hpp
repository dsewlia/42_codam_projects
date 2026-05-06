/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsewlia <dsewlia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 14:55:49 by driemers      #+#    #+#                 */
/*   Updated: 2025/07/23 17:40:19 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Socket.hpp"

#include "User.hpp"
#include <unordered_set>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <poll.h>
#include <set>
#include "Message.hpp"

# define POLL_TIMEOUT 100

class Channel;

struct Clientstate{
	User							user;
	std::string						nickname;
	std::string						buffer;
	std::unordered_set<std::string>	joinedChannels = {};
	bool							hasNick = false;
	bool							hasUser = false;
	bool							hasPass = false;
	bool							hasCapLs = false;
	bool							hasCapEnd = false;
	bool							registered = false;
	time_t							lastActivity = 0;
	bool							awaitingPong = false;
	std::string						lastPingToken;
};

class Server {

	private:
		//----variables----
		std::string			_serverName;
		Socket 				_socket;
		std::string			_password;
		std::vector<pollfd>	_pollFd;

		//Message				_message;

		std::unordered_map<int, Clientstate>		_clientStates; // fd -> state
		std::unordered_map<std::string, Channel>	_channels; // channel name -> channel
		static std::set<std::string>				_capabilities; // set of known nicknames to prevent duplicates

		//----functions----
		void _setupPoll();
		int _handleNewConection();
		void _handleClientData(int clientFd);
		void _handleServerMsg();
		void _initDefaultChannel();
		int _nickValidation(int clientFd, const std::string &newNick);

		void _parseAndexecuteComand(int clientFd, const std::string &command);
		//----command-handler----
		void _handleJoin(int clientFd, const std::string &channelName, bool defaulJoin);
		void _handleMsg(int clientFd, const std::string &targetRaw, const std::string &messageRaw);
		void _handleNick(int clientFd, const std::string &newNick);
		//----capabilities----
		void _handleCap(int clientFd, const std::string &cap);
		void _handleLs(int clientFd, const std::string &version);
		void _handleReq(int clientFd, const std::string &req);
		//----utility----
		// void _parseConnectionData()

		// commands
		int	addUser(Channel& c, User& user);
		void _checkClientPings();
		void _preParsing(const std::string &command, int clientFd);
		void _registerUser(Clientstate &clientstate);

	public:
		std::string getServerName() {return (_serverName);}
		std::unordered_map<std::string, Channel>& getChannels()
		{ return (_channels); };
		std::unordered_map<int, Clientstate>& getClients()
		{ return (_clientStates); };
		struct Clientstate* getClientState(int fd);
		void	parsing(std::string &msg, int fd, Server &server);

		//double check for existence, copy channels from server to channel class move to cpp file
		void	addChannelToDatabase(Channel &newChannel);
		//commands
		// return 0 on succes and an error code on fail/no op perms for User.
		int	userSendMessage(Channel& c, User& user, std::string& message);
		int	userAcceptInvite(Channel& c, User& user);
		int	userJoin(Channel& c, User& user, std::string *pass);
		int	isOp(Channel& c, User& user);
		// these fuction require an oprator User for perms.
		int	inviteUser(Channel& c, User& user, User& op);
		int	kickUser(Channel& c, User& user, User& op);
		int	setTopic(Channel& c, std::string& topic, User& op);
		int	modeI(Channel& c, bool is_inv, User& op);
		int	modeT(Channel& c, bool retrict, User& op);
		int	modeK(Channel& c, bool has_pass, std::string *new_pass, User& op);
		int	modeO(Channel& c, bool set_op, User &user, User& op);
		int	modeL(Channel& c, bool has_limit, int new_limit, User& op);
		void _sendToClient(int fd, const std::string &msg);
		void _broadcastToChannel(const std::string &channel, const std::string &msg, int excludeFd = -1);
		void _disconnectClient(int clientFd);

		Server(int port, const std::string &password);
		~Server();

		void	run();
};
