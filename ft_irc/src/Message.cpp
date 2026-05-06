/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Message.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: driemers <driemers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/16 10:37:35 by dsewlia       #+#    #+#                 */
/*   Updated: 2025/07/23 10:21:50 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Server.hpp"
#include "Logger.hpp"

Message::~Message()
{
}

bool	Message::_userExists(std::string userName)
{
	if (_getClientFd(userName) < 0)
		return (false);
	else
		return (true);
}

bool	Message::_checkChannelName(const std::string &name)
{
	if (name.empty() || name.length() > MAX_CHANNEL_LENGTH)
		return false;
	if (name[0] != '#' && name[0] != '&')
		return false;
	for (char ch : name)
	{
		if (ch == ' ' || ch == ',' || ch == ':' || ch == '\x00' || ch == '\x07' || (ch >= 0 && ch <= 32))
			return false;
	}
	return true;
}

bool	Message::_checkNickName(const std::string &name)
{
	if (name.empty() || name.length() > MAX_NICK_LENGTH)
		return false;
	if (!isalpha(name[0]))
		return false;
	for (char ch : name)
	{
		if (!isalnum(ch) && ch != '-' && ch != '[' && ch != ']' && ch != '\\' && ch != '`' && ch != '^' && ch != '{' && ch != '}')
			return false;
	}
	return true;
}

std::string	Message::_getClientNick(int fd)
{
	std::unordered_map<int, Clientstate>		_clientStates = _server.getClients();
	const auto &it = _clientStates.find(fd);
	if (it == _clientStates.end())
		return ("");
	else
		return (it->second.nickname);
}

int	Message::_getClientFd(std::string targetNick)
{
	std::unordered_map<int, Clientstate>		_clientStates = _server.getClients();
	for (const auto &it : _clientStates)
	{
		if (targetNick == it.second.nickname)
			return (it.first);
	}
	return (-1);
}

Channel*	Message::_getChannel(std::string name)
{
	std::unordered_map<std::string, Channel>	&_allChannels = _server.getChannels();
	const auto &it = _allChannels.find(name);
	if (it != _allChannels.end())
	{
		_criticalError = false;
		return (&it->second);
	}
	_criticalError = true;
	return (NULL);
}

void	Message::_updateTargetList(std::string targets)
{
	unsigned long	len = targets.size();
	std::string temp;
	for (unsigned long i = 0; i < len; i++)
	{
		temp.clear();
		while (i < len && targets[i] != ',')
		{
			temp += targets[i];
			i++;
		}
		if (!temp.empty())
		{
			this->_target.push_back(temp);
			this->_targetFound.push_back(false);
		}
	}
	std::unordered_map<int, Clientstate> &_allClientStates = _server.getClients();
	for (unsigned long i = 0; i< _target.size(); i++)
	{
		for (const auto &pair : _allClientStates)
		{
			if (pair.second.nickname == _target[i])
			{
				_targetFound[i] = true;
				this->_targetState.push_back(pair.second);
				break ;
			}
		}
	}
}

std::string	Message::_draftErrorMessage(int errnum, int targetFd, std::string targetNick)
{
	//:<server> <3-digit-code> <target-nick> <params..> :<description>
	std::string	info;

	if (!_trailing.empty())
	{
		_param.pop_back();
	}
	for(unsigned long i = 0; i < _param.size(); i++)
	{
		if (i != 0)
			info += " ";
		info += _param[i];
	}
	if (targetNick.size() == 0)
		targetNick = _getClientNick(targetFd);
	if (targetNick.size() == 0)
		targetNick = "*";
	std::ostringstream	temp;
	temp << std::setw(3) << std::setfill('0') << errnum;
	std::string errormessage = ":" + _server.getServerName() + " " + temp.str() + " " + targetNick + " " + info + " :" + _getErrorMessage(errnum) + "\r\n";
	return (errormessage);
}

//BIG CHANGE. PREFIX IS NOT NICK!! PREFIX IS NICK!USER@HOST. make changes accordingly!!
Message::Message(std::string &msg, int fd, Server &server) \
	: _fd(fd), _server(server), _channels(server.getChannels()), _userState(server.getClientState(fd))
{
	unsigned long			i = 0;
	unsigned long			len = msg.size();
	std::string	word;

	this->_criticalError = false;
	if (_userState == nullptr)
	{
		this->_criticalError = true;
	}
	while (msg[i] == ' ' || msg[i] == '\t') //to remove '\t'
		i++;
	this->_prefix.clear();
	if (msg[i] == ':')
	{
		i++;
		while (i < len && msg[i] != ' ' && msg[i] != '\t')  //to remove '\t'
		{
			this->_prefix += msg[i];
			i++;
		}
	}
	this->_userNick = _getClientNick(fd);
	std::string username = this->_userState->user.getUsername();
	std::string hostname = this->_userState->user.getHostname();
	std::string temp1 = this->_userNick;
	if (!username.empty())
	{
		temp1 += "!";
		temp1 += username;
		if (!hostname.empty())
		{
			temp1 += "@";
			temp1 += hostname;
		}
	}
	if (this->_prefix.length() == 0)
		this->_prefix = temp1;
	//to check if we have to define the prefix irrespective of what comes in or do we keep as is!
	while (msg[i] == ' ' || msg[i] == '\t') //to remove '\t'
		i++;
	while (i < len && msg[i] != ' ' && msg[i] != '\t')  //to remove '\t'
	{
		this->_command += msg[i];
		i++;
	}
	for (char &ch : this->_command)
	{
		ch = std::toupper(static_cast<unsigned char>(ch));
	}
	while (i < len)
	{
		while (msg[i] == ' ' || msg[i] == '\t') //to remove '\t'
			i++;
		if (msg[i] == ':')
		{
			i++;
			while (i < len)
			{
				this->_trailing += msg[i];
				i++;
			}
			this->_param.push_back(this->_trailing);
			break ;
		}
		word.clear();
		while (i < len && msg[i] != ' ' && msg[i] != '\t')
		{
			word += msg[i];
			i++;
		}
		if (!word.empty())
		{
			this->_param.push_back(word);
			word.clear();
		}
	}
	if (this->_userState->registered == false)
		this->_criticalError = true; //check for NICK, PASS, USER
}

bool	Message::_channelExists(std::string channelName)
{
	const auto &it = this->_channels.find(channelName);
	if (it != this->_channels.end())
		return (true);
	else
		return (false);
}

bool	Message::_channelHasUser(int targetFd, std::string channelName)
{
	std::unordered_map<int, struct Clientstate> _allClientStates = _server.getClients();
	struct Clientstate targetClient;
	const auto &it = _allClientStates.find(targetFd);
	if (it != _allClientStates.end())
	{
		targetClient = it->second;
	}
	else
	{
		return (false);
	}
	if (targetClient.joinedChannels.find(channelName) != targetClient.joinedChannels.end())
		return (true);
	return (false);
}

void	Message::_NICK()
{
	if (this->_param.size() == 0)
	{
		Logger::get()->log(this->_userNick + " tried to change nickname with any parameters", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	if (this->_userNick == this->_param[0])
	{
		Logger::get()->log(this->_userNick + " tried changing the nick name to the one that is already in use", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NICKNAMEINUSE, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	if (_userExists(this->_param[0]))
	{
		Logger::get()->log(this->_userNick + " tried changing the nick name that is taken by another client", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NICKCOLLISION, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	if (_checkNickName(this->_param[0]) == false)
	{
		Logger::get()->log(this->_userNick + " tried changing the nick name which had bad format", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_ERRONEUSNICKNAME, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	std::string oldNick = this->_userState->user.getNickname();
	std::string newNick = this->_param[0];
	this->_userState->user.setNickname(this->_param[0]);
	this->_userState->nickname = this->_param[0];
	this->_response.clear();
	this->_response = ":" + this->_prefix + " NICK :" + this->_param[0] + "\r\n";
	this->_server._sendToClient(this->_fd, this->_response);
	Logger::get()->log(this->_userNick + " changed their nick name to " + this->_param[0], INFO);
	for (const std::string &channelName : this->_userState->joinedChannels)
	{
		this->_server._broadcastToChannel(channelName, this->_response, this->_fd);
	}
}

void	Message::_JOIN(void)
{
	std::vector<t_channelKey>	cK;
	std::vector<int>			errorCode;
	t_channelKey				tempCK;
	int							errnum = 0;
	std::vector<std::string>	tempChannel;
	std::vector<std::string>	tempKey;
	std::string					temp;
	unsigned long							len;

	if (this->_param.size() == 0 || this->_param.size() > 2)
	{
		Logger::get()->log(this->_userNick + " tried joining a channel but the param list did not comply to the standards", WARNING);
		errnum = ERRNO_NEEDMOREPARAMS;
		this->_response = _draftErrorMessage(errnum, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	else
	{
		for (unsigned long i = 0; i < this->_param[0].length(); i++)
		{
			temp.clear();
			while (this->_param[0][i] != ',' && i < this->_param[0].length())
			{
				temp += this->_param[0][i];
				i++;
			}
			tempChannel.push_back(temp);
		}
		if (this->_param.size() >= 2 && !this->_param[1].empty())
		{
			for (unsigned long i = 0; i < this->_param[1].length(); i++)
			{
				temp.clear();
				while (this->_param[1][i] != ',' && i < this->_param[1].length())
				{
					temp += this->_param[1][i];
					i++;
				}
			tempKey.push_back(temp);
			}
		}
		len = tempChannel.size();
		for (unsigned long i = 0; i < len; i++)
		{
			tempCK.channelName.clear();
			tempCK.key.clear();
			tempCK.channelName = tempChannel[i];
			if (i < tempKey.size())
			{
				tempCK.key = tempKey[i];
			}
			cK.push_back(tempCK);
		}
		for (unsigned long i = 0; i < len; i++)
		{
			const auto &it = this->_channels.find(cK[i].channelName);
			if (it == this->_channels.end())
			{
				if (_checkChannelName(cK[i].channelName) == false)
				{
					Logger::get()->log(this->_userNick + " tried creating a channel with bad mask", WARNING);
					this->_response.clear();
					this->_response = _draftErrorMessage(ERRNO_BADCHANNELMASK, this->_fd, this->_userNick); //need to implement BADCHANNELMASK
					_server._sendToClient(this->_fd, this->_response);
					continue ;
				}
				if (i < tempKey.size())
				{
					Channel newChannel(_userState->user, cK[i].channelName, this->_server, cK[i].key);
					_server.addChannelToDatabase(newChannel);
				}
				else
				{
					Channel newChannel(_userState->user, cK[i].channelName, this->_server);
					_server.addChannelToDatabase(newChannel);
				}
				Logger::get()->log(this->_userNick + " created the channel " + cK[i].channelName, INFO);
				_userState->joinedChannels.insert(cK[i].channelName);
				this->_response.clear();
				this->_response = ":" + this->_prefix + " JOIN :" + cK[i].channelName + "\r\n";
				_server._sendToClient(this->_fd, this->_response);
				std::string newTopicMsg = "TOPIC " + cK[i].channelName + "\r\n";
				_server.parsing(newTopicMsg, this->_fd, this->_server);
				std::string newmsg = "MODE " + cK[i].channelName + "\r\n";
				_server.parsing(newmsg, this->_fd, this->_server);
				std::string newResponse = ":" + _server.getServerName() + " " + std::to_string(353) + " " + this->_userNick + " = " + cK[i].channelName + " :@" + this->_userNick + "\r\n";
				_server._sendToClient(this->_fd, newResponse);
				std::string newResponse2 = ":" + _server.getServerName() + " " + std::to_string(366) + " " + this->_userNick + " " + cK[i].channelName + " :End of /NAMES list \r\n";
				_server._sendToClient(this->_fd, newResponse2);
				continue;
			}
			Channel &targetChannel = it->second;
			if (i < tempKey.size())
			{
				errnum = _server.userJoin(targetChannel, _userState->user, &cK[i].key);
			}
			else
			{
				errnum = _server.userJoin(targetChannel, _userState->user, NULL);
			}
			if (errnum == 0)
			{
				Logger::get()->log(this->_userNick + " joined the channel " + cK[i].channelName, INFO);
				this->_response.clear();
				_userState->joinedChannels.insert(cK[i].channelName);
				this->_response = ":" + this->_prefix + " JOIN :" + targetChannel.getChannelName() + "\r\n";
				_server._sendToClient(this->_fd, this->_response);
				_server._broadcastToChannel(targetChannel.getChannelName(), this->_response, this->_fd);
				std::string channelTopic = targetChannel.getChannelTopic();
				this->_response.clear();
				if (channelTopic.empty())
				{
					this->_response = ":" + _server.getServerName() + " " + std::to_string(331) + " " + this->_userNick + " " + targetChannel.getChannelName() + " :" + "No topic is set\r\n";
				}
				else
				{
					this->_response = ":" + _server.getServerName() + " " + std::to_string(332) + " " + this->_userNick + " " + targetChannel.getChannelName() + " :" + channelTopic + "\r\n";
				}
				_server._sendToClient(this->_fd, this->_response);
				std::string newMessage = "MODE " + targetChannel.getChannelName() + " \r\n";
				_server.parsing(newMessage, this->_fd, this->_server);
				std::string nickList;
				std::unordered_set<int> userList = targetChannel.getMembers();
				std::unordered_map<int, Clientstate>		_clientStates = _server.getClients();
				for (const auto &userFd : userList)
				{
					const auto &it = _clientStates.find(userFd);
					if (it != _clientStates.end())
					{
						Clientstate &temp = it->second;
						if (_server.isOp(targetChannel, temp.user) == 0)
							nickList += "@";
						nickList += temp.nickname + " ";
					}
				}
				if (!nickList.empty() && nickList.back() == ' ')
					nickList.pop_back();
				this->_response.clear();
				if (!nickList.empty())
				{
					this->_response = ":" + _server.getServerName() + " " + std::to_string(353) + " " + this->_userNick + " = " + targetChannel.getChannelName() + " :" + nickList + "\r\n";
					_server._sendToClient(this->_fd, this->_response);
				}
				this->_response.clear();
				this->_response = ":" + _server.getServerName() + " " + std::to_string(366) + " " + this->_userNick + " " + targetChannel.getChannelName() + " :End of /NAMES list \r\n";
				_server._sendToClient(this->_fd, this->_response);
			}
			else
			{
				Logger::get()->log(this->_userNick + " tried to join the channel " + cK[i].channelName + " but an error occured", WARNING);
				this->_response.clear();
				this->_response = _draftErrorMessage(errnum, this->_fd, this->_userNick);
				_server._sendToClient(this->_fd, this->_response);
			}
		}
	}
}

void	Message::_QUIT(void)
{
	if (this->_param.size() == 0)
	{
		Logger::get()->log(this->_userNick + " quit without saying anything", INFO);
		this->_response = ":" + this->_prefix + " QUIT :" + "Client Quit" + "\r\n"; //need to edit
	}
	else
	{
		Logger::get()->log(this->_userNick + " quit with the message :" + this->_param[0], INFO);
		this->_response = ":" + this->_prefix + " QUIT :" + this->_param[0] + "\r\n";
	}
	for (const auto &temp : this->_userState->joinedChannels)
	{
			const auto &it = this->_channels.find(temp);
			if (it != this->_channels.end())
			{
				Channel &temp1 = it->second;
				temp1.removeMember(this->_fd);
				_server._broadcastToChannel(temp, this->_response, this->_fd);
			}
	}
	this->_server._disconnectClient(this->_fd);
}

void	Message::_PRIVMSG()
{
	std::string					msg;
	std::string					temp;
	// std::vector<std::string>	target;

	if (this->_param.size() < 2)
	{
		Logger::get()->log(this->_userNick + " tried sending a message but param were not as per standards", WARNING);
		msg = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		this->_server._sendToClient(this->_fd, msg);
		return ;
	}
	_updateTargetList(_param[0]);
	for (unsigned long i = 0; i < this->_target.size(); i++)
	{
		msg.clear();
		msg = ":" + this->_prefix + " PRIVMSG " + _target[i] + " :" + _param[1] + "\r\n";
		if (this->_target[i][0] == '#' || this->_target[i][0] == '&')
		{
			if (!_channelExists(this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a message to channel that does not exist", WARNING);
				msg.clear();
				msg = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
				this->_server._sendToClient(this->_fd, msg);
				return ;
			}
			if (!_channelHasUser(this->_fd, this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a message to a channel that they are not part of", WARNING);
				msg.clear();
				msg = _draftErrorMessage(ERRNO_NOTONCHANNEL, this->_fd, this->_userNick);
				this->_server._sendToClient(this->_fd, msg);
				return ;
			}
			Logger::get()->log(this->_userNick + " sent the following message to the channel " + this->_target[i] + " :" + _param[1], INFO);
			this->_server._broadcastToChannel(this->_target[i], msg, this->_fd);
		}
		else
		{
			if (!_userExists(this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a message to a user that does not exist", WARNING);
				msg.clear();
				msg = _draftErrorMessage(ERRNO_NOSUCHNICK, this->_fd, this->_userNick);
				this->_server._sendToClient(this->_fd, msg);
				return ;
			}
			Logger::get()->log(this->_userNick + " sent the following message to user " + this->_target[i] + " :" + _param[1], INFO);
			this->_server._sendToClient(_getClientFd(this->_target[i]), msg);
		}
	}
	return ;
}

void	Message::_PASS()
{
	Logger::get()->log(this->_userNick + " tried to reregister", WARNING);
	this->_response.clear();
	this->_response = _draftErrorMessage(ERRNO_ALREADYREGISTERED, this->_fd, this->_userNick);
	_server._sendToClient(this->_fd, this->_response);
	return ;
}

void	Message::_USER()
{
	Logger::get()->log(this->_userNick + " tried to reregister", WARNING);
	this->_response.clear();
	this->_response = _draftErrorMessage(ERRNO_ALREADYREGISTERED, this->_fd, this->_userNick);
	_server._sendToClient(this->_fd, this->_response);
	return ;
}

void	Message::_NOTICE(void)
{
	std::string					msg;
	std::string					temp;

	if (this->_param.size() < 2)
		return ;
	_updateTargetList(_param[0]);
	for (unsigned long i = 0; i < this->_target.size(); i++)
	{
		msg.clear();
		msg = ":" + this->_prefix + " NOTICE " + _target[i] + " :" + _param[1] + "\r\n";
		if (this->_target[i][0] == '#' || this->_target[i][0] == '&')
		{
			if (!_channelExists(this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a notice to a channel that does not exist", WARNING);
				continue ;
			}
			if (!_channelHasUser(this->_fd, this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a notice to a channel they are not on", WARNING);
				continue ;
			}
			Logger::get()->log(this->_userNick + " sent the following notice to the channel " + _target[i] + " :" + _param[1], INFO);
			this->_server._broadcastToChannel(_target[i], msg);
		}
		else
		{
			if (!_userExists(this->_target[i]))
			{
				Logger::get()->log(this->_userNick + " tried sending a notice to a user that does not exist", WARNING);
				continue ;
			}
			Logger::get()->log(this->_userNick + " sent the following notice to the user " + _target[i] + " :" + _param[1], INFO);
			this->_server._sendToClient(_getClientFd(_target[i]), msg);
		}
	}
	return ;
}

void	Message::_PART()
{
	std::string					msg;
	std::string					temp;

	if (this->_param.empty())
	{
		Logger::get()->log(this->_userNick + " sent a part command with parameters", WARNING);
		msg = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		this->_server._sendToClient(this->_fd, msg);
		return ;
	}
	_updateTargetList(_param[0]);
	for (unsigned long i = 0; i < this->_target.size(); i++)
	{
		const auto &it = this->_channels.find(this->_target[i]);
		if (it == this->_channels.end())
		{
			Logger::get()->log(this->_userNick + " tried to part with a channel that does not exist", WARNING);
			msg.clear();
			msg = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
			this->_server._sendToClient(this->_fd, msg);
			continue ;
		}
		Channel &targetChannel = it->second;
		if (!targetChannel.hasMember(this->_fd))
		{
			Logger::get()->log(this->_userNick + " tried to part with a channel of which they were not a member of", WARNING);
			msg.clear();
			msg = _draftErrorMessage(ERRNO_NOTONCHANNEL, this->_fd, this->_userNick);
			this->_server._sendToClient(this->_fd, msg);
			continue ;
		}
		targetChannel.removeMember(this->_fd);
		_userState->joinedChannels.erase(this->_target[i]);
		Logger::get()->log(this->_userNick + " parted ways with the channel " + this->_target[i], INFO);
		msg = ":" + this->_prefix + " PART :" + this->_target[i] + "\r\n";
		this->_server._sendToClient(this->_fd, msg);
		this->_server._broadcastToChannel(_target[i], msg);
	}
}

void	Message::_TOPIC()
{
	std::string	msg;
	std::string	topic;

	if (_param.empty())
	{
		Logger::get()->log(this->_userNick + " tried to use the command topic with parameters", WARNING);
		msg = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, "");
		this->_server._sendToClient(this->_fd, msg);
		return ;
	}
	const auto &it = this->_channels.find(_param[0]);
	if (it == this->_channels.end())
	{
		Logger::get()->log(this->_userNick + " tried to get/change the topic of a channel that does not exist", WARNING);
		msg = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, "");
		this->_server._sendToClient(this->_fd, msg);
		return ;
	}
	Channel &targetChannel = it->second;
	topic = targetChannel.getChannelTopic();
	if (_param.size() == 1)
	{
		msg.clear();
		msg = ":" + _server.getServerName() + " ";
		if (topic.empty())
		{
			Logger::get()->log(this->_userNick + " tried to get the topic of a channel. But there was no topic set", INFO);
			msg = msg + "331 " + _param[0] + " :No topic is set" + "\r\n";
			this->_server._sendToClient(this->_fd, msg);
			return ;
		}
		else
		{
			Logger::get()->log(this->_userNick + " accessed the topic of channel " + this->_param[0], INFO);
			msg = msg + "332 " + _param[0] + " :" + topic + "\r\n";
			this->_server._sendToClient(this->_fd, msg);
			return ;
		}
	}
	else
	{
		int errnum = _server.setTopic(targetChannel, this->_param[1], this->_userState->user);
		if (errnum == 0)
		{
			Logger::get()->log(this->_userNick + " chaned the topic of the channel " + this->_param[0] + " to :" + this->_param[1], INFO);
			msg = ":" + this->_prefix + " TOPIC " + this->_param[0] + " :" + this->_param[1] + "\r\n";
			this->_server._broadcastToChannel(this->_param[0], msg);
		}
		else
		{
			Logger::get()->log(this->_userNick + " chaned the topic of the channel " + this->_param[0] + " but was unsuccessful", WARNING);
			this->_response.clear();
			this->_response = _draftErrorMessage(errnum, this->_fd, this->_userNick);
			_server._sendToClient(this->_fd, this->_response);
		}
		return ;
	}
}

void	Message::_INVITE()
{
	if (this->_param.size() < 2)
	{
		Logger::get()->log(this->_userNick + " tried to use invite command without the right paramaters", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	int	targetFd = _getClientFd(this->_param[0]);
	if (targetFd < 0)
	{
		Logger::get()->log(this->_userNick + " tried to use invite a user that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHNICK, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	struct Clientstate *targetClientState = _server.getClientState(targetFd);
	std::unordered_map<int, Clientstate>		allClientStates = _server.getClients();
	const auto &it = allClientStates.find(targetFd);
	if (targetClientState == nullptr || it == allClientStates.end())
	{
		Logger::get()->log(this->_userNick + " tried to use invite a user that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHNICK, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Channel *targetChannel = _getChannel(this->_param[1]);
	if (this->_criticalError == true)
	{
		Logger::get()->log(this->_userNick + " tried to use invite a user to a channel that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	int errnum = _server.inviteUser(*targetChannel, targetClientState->user, _userState->user);
	if (errnum > 0)
	{
		Logger::get()->log(this->_userNick + " tried to use invite " + targetClientState->nickname + " to the channel " + targetChannel->getChannelName() + " but was unsuccessful", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(errnum, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Logger::get()->log(this->_userNick + " invited " + targetClientState->nickname + " to the channel " + targetChannel->getChannelName(), INFO);
	this->_response.clear();
	this->_response = ":" + _server.getServerName() +" 341 " + this->_userNick + " " + this->_param[0] + " " + this->_param[1] + "\r\n";
	_server._sendToClient(this->_fd, this->_response);
	this->_response.clear();
	this->_response = ":" + this->_prefix + " INVITE " + this->_param[0] + " " + this->_param[1] + "\r\n";
	_server._sendToClient(targetFd, this->_response);
}

void	Message::_KICK()
{
	if (this->_param.size() < 2)
	{
		Logger::get()->log(this->_userNick + " tried to use kick command without the right paramaters", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	const auto &it = this->_channels.find(this->_param[0]);
	if (it == this->_channels.end())
	{
		Logger::get()->log(this->_userNick + " tried to use kick a user from a channel that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Channel &targetChannel = it->second;
	int targetFd = _getClientFd(this->_param[1]);
	if (targetFd < 0)
	{
		Logger::get()->log(this->_userNick + " tried to use kick a user from a channel but the user does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHNICK, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	std::unordered_map<int, Clientstate>		&_clientStates = _server.getClients();
	const auto &it2 = _clientStates.find(targetFd);
	if (it2 == _clientStates.end())
	{
		Logger::get()->log(this->_userNick + " tried to use kick a user from a channel but the user does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHNICK, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Clientstate &targetUserState = it2->second;
	int errnum = _server.kickUser(targetChannel, targetUserState.user, this->_userState->user);
	if (errnum > 0)
	{
		Logger::get()->log(this->_userNick + " tried to kick " + this->_param[1] + " from " + this->_param[0] + " but was unsuccessful", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(errnum, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	this->_response.clear();
	targetUserState.joinedChannels.erase(this->_param[0]);
	this->_response = ":" + this->_prefix + " KICK " + this->_param[0] + " " + this->_param[1];
	if (this->_param.size() >= 3)
	{
		Logger::get()->log(this->_userNick + " kicked " + this->_param[1] + " from " + this->_param[0] + " with the following message :" + this->_param[2], INFO);
		this->_response += " :";
		this->_response += this->_param[2];
		this->_response += "\r\n";
	}
	else
	{
		Logger::get()->log(this->_userNick + " kicked " + this->_param[1] + " from " + this->_param[0], INFO);
		this->_response += "\r\n";
	}
	_server._sendToClient(targetFd, this->_response);
	_server._broadcastToChannel(this->_param[0], this->_response);
}

void	Message::_MODE()
{
	if (_param.size() == 0)
	{
		Logger::get()->log(this->_userNick + " tried to use the mode command but the params where not as per standards", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	if (this->_param[0][0] != '#' && this->_param[0][0] != '&')
	{
		if (this->_param[0] != this->_userNick)
		{
			Logger::get()->log(this->_userNick + " tried to use the user mode but a critical error occurred", ERROR);
			this->_response.clear();
			this->_response = _draftErrorMessage(ERRNO_USERSDONTMATCH, this->_fd, this->_userNick);
			_server._sendToClient(this->_fd, this->_response);
			return ;
		}
		Logger::get()->log(this->_userNick + " tried to use the user mode but our server does not implement it", WARNING);
		//user mode is ignored since we do not implement any user mode.
		return ;
	}
	const auto &it = this->_channels.find(this->_param[0]);
	if (it == this->_channels.end())
	{
		Logger::get()->log(this->_userNick + " tried to change the mode of a channel that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Channel &targetChannel = it->second;
	if (_param.size() == 1)
	{
		std::string		flags;
		std::vector<std::string>	responseParams;
		if (targetChannel.isInviteFalgSet())
			flags += "i";
		if (targetChannel.isTopicFlagSet())
			flags += "t";
		if (targetChannel.isKeyFlagSet())
		{
			flags += "k";
			responseParams.push_back(targetChannel.getChannelKey());
		}
		if (targetChannel.getUserLimit() > 0)
		{
			flags += "l";
			responseParams.push_back(std::to_string(targetChannel.getUserLimit()));
		}
		if (flags.length() > 0)
		{
			flags = "+" + flags;
		}
		this->_response.clear();
		this->_response = ":" + _server.getServerName() + " 324 " + this->_prefix + " " + this->_param[0];
		if (!flags.empty())
			this->_response = this->_response + " " + flags;
		for (unsigned long i = 0; i < responseParams.size(); i++)
			this->_response = this->_response + " " + responseParams[i];
		this->_response += "\r\n";
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	bool	setFlag;
	if (_param[1][0] == '+')
		setFlag = true;
	else if (_param[1][0] == '-')
		setFlag = false;
	else
	{
		Logger::get()->log(this->_userNick + " tried to change the mode of a channel but the server does not recognize the mode change", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_UNKNOWNMODE, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	unsigned long paramIndex = 2;
	int errnum = 0;
	std::string modeIndicator;
	std::string additionaParam;
	std::string channelNameParam = this->_param[0];
	for (unsigned long i = 1; i < this->_param[1].length(); i++)
	{
		additionaParam.clear();
		modeIndicator.clear();
		if (setFlag)
			modeIndicator += "+";
		else
			modeIndicator += "-";
		modeIndicator += this->_param[1][i];
		errnum = 0;
		if (this->_param[1][i] == 'i')
			errnum = _server.modeI(targetChannel, setFlag, this->_userState->user);
		else if (this->_param[1][i] == 't')
			errnum = _server.modeT(targetChannel, setFlag, this->_userState->user);
		else if (this->_param[1][i] == 'k')
		{
			if (setFlag && this->_param.size() <= paramIndex)
				errnum = ERRNO_NEEDMOREPARAMS;
			else if (setFlag)
				errnum = _server.modeK(targetChannel, true, &this->_param[paramIndex++], this->_userState->user);
			else
				errnum = _server.modeK(targetChannel, false, NULL, this->_userState->user);

		}
		else if (this->_param[1][i] == 'l')
		{
			if (setFlag && this->_param.size() <= paramIndex)
				errnum = ERRNO_NEEDMOREPARAMS;
			else if (setFlag)
				errnum = _server.modeL(targetChannel, true, std::atoi(this->_param[paramIndex++].c_str()), this->_userState->user);
			else
				errnum = _server.modeL(targetChannel, false, -1, this->_userState->user);
		}
		else if (this->_param[1][i] == 'o')
		{
			if (setFlag && this->_param.size() <= paramIndex)
				continue;
			else if (setFlag)
			{
				additionaParam = this->_param[paramIndex];
				int targetFd = _getClientFd(this->_param[paramIndex++]);
				if (targetFd < 0)
					errnum = ERRNO_NOSUCHNICK;
				else
				{
					std::unordered_map<int, Clientstate>		&_clientStates = _server.getClients();
					const auto &it = _clientStates.find(targetFd);
					if (it == _clientStates.end())
						errnum = ERRNO_NOSUCHNICK;
					else
					{
						Clientstate &targetState = it->second;
						errnum = _server.modeO(targetChannel, true, targetState.user, this->_userState->user);
					}
				}
			}
			else
			{
				if (this->_param.size() <= paramIndex)
				{
					//check this once
					errnum = _server.modeO(targetChannel, false, this->_userState->user, this->_userState->user);
				}
				else
				{
					additionaParam = this->_param[paramIndex];
					int targetFd = _getClientFd(this->_param[paramIndex++]);
					if (targetFd < 0)
						errnum = ERRNO_NOSUCHNICK;
					else
					{
						std::unordered_map<int, Clientstate>		&_clientStates = _server.getClients();
						const auto &it = _clientStates.find(targetFd);
						if (it == _clientStates.end())
							errnum = ERRNO_NOSUCHNICK;
						else
						{
							Clientstate &targetState = it->second;
							errnum = _server.modeO(targetChannel, false, targetState.user, this->_userState->user);
						}
					}
				}

			}
		}
		else
			errnum = ERRNO_UNKNOWNMODE;
		if (errnum > 0)
		{
			Logger::get()->log(this->_userNick + " tried to change the mode of a channel but was unsuccessful", WARNING);
			std::ostringstream	temp;
			temp << std::setw(3) << std::setfill('0') << errnum;
			std::string custResponse = ":" + _server.getServerName() + " " + temp.str() + " " + this->_userNick + " " + _param[0] + " " + modeIndicator + " " + ":" + _getErrorMessage(errnum) + "\r\n";
			_server._sendToClient(this->_fd, custResponse);
		}
		else
		{
			Logger::get()->log(this->_userNick + " implemented the mode " + modeIndicator + " to channel " + channelNameParam, INFO);
			this->_response.clear();
			this->_response = ":" + this->_prefix + " MODE " + channelNameParam + " " + modeIndicator;
			if (!additionaParam.empty())
				this->_response = this->_response + " " + additionaParam + "\r\n";
			else
				this->_response += "\r\n";
			_server._sendToClient(this->_fd, this->_response);
			_server._broadcastToChannel(this->_param[0], this->_response, this->_fd);
		}
	}
}


void    Message::_PING()
{
    if (!_param.empty()) {
        std::string token = _param[0];
        _server._sendToClient(this->_fd, "PONG :" + token + "\r\n");
		std::cout << "PONG :" << token << "\r\n";
	} else {
		Logger::get()->log(this->_userNick + " sent a PING command without parameters", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return;
	}
    Clientstate* cs = _server.getClientState(this->_fd);
    if (cs) {
        cs->awaitingPong = false;
        cs->lastActivity = time(NULL);
    }
}

void    Message::_PONG()
{
    Clientstate* cs = _server.getClientState(this->_fd);
    if (cs) {
        // Only accept PONG if it matches the last server-sent token
        if (cs->awaitingPong && !_param.empty() && _param[0] == cs->lastPingToken) {
            cs->awaitingPong = false;
            cs->lastActivity = time(NULL);
        } else {
            return;
        }
    }
}

void	Message::_WHO()
{
	if (this->_param.size() == 0)
	{
		Logger::get()->log(this->_userNick + " tried to use WHO command without parameters", WARNING);
		this->_response.clear();
		this->_draftErrorMessage(ERRNO_NEEDMOREPARAMS, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		//add log
		return ;
	}
	if (this->_param[0][0] != '#' && this->_param[0][0] != '&')
	{
		Logger::get()->log(this->_userNick + " tried to use WHO command with bad channel mask", WARNING);
		this->_response.clear();
		this->_draftErrorMessage(ERRNO_BADCHANNELMASK, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	const auto &it = this->_channels.find(this->_param[0]);
	if (it == this->_channels.end())
	{
		Logger::get()->log(this->_userNick + " tried to use WHO command on a channel that does not exist", WARNING);
		this->_response.clear();
		this->_response = _draftErrorMessage(ERRNO_NOSUCHCHANNEL, this->_fd, this->_userNick);
		_server._sendToClient(this->_fd, this->_response);
		return ;
	}
	Channel &targetChannel = it->second;
	std::string nickList;
	std::unordered_set<int> userList = targetChannel.getMembers();
	std::unordered_map<int, Clientstate>		_clientStates = _server.getClients();
	for (const auto &userFd : userList)
	{
		const auto &it = _clientStates.find(userFd);
		if (it != _clientStates.end())
		{
			Clientstate &temp = it->second;
			if (_server.isOp(targetChannel, temp.user) == 0)
				nickList += "@";
			nickList += temp.nickname + " ";
		}
	}
	if (!nickList.empty() && nickList.back() == ' ')
		nickList.pop_back();
	this->_response.clear();
	if (!nickList.empty())
	{
		this->_response = ":" + _server.getServerName() + " " + std::to_string(353) + " " + this->_userNick + " = " + targetChannel.getChannelName() + " :" + nickList + "\r\n";
		_server._sendToClient(this->_fd, this->_response);
	}
	this->_response.clear();
	this->_response = ":" + _server.getServerName() + " " + std::to_string(366) + " " + this->_userNick + " " + targetChannel.getChannelName() + " :End of /NAMES list \r\n";
	_server._sendToClient(this->_fd, this->_response);
	_server._broadcastToChannel(targetChannel.getChannelName(), this->_response, this->_fd);
}

void	Message::executeCommand(void)
{
	if (this->_criticalError == true)
	{
		Logger::get()->log( "A critical error occured while parsing the message from " + this->_userNick, ERROR);
		return ;
	}
	if (this->_command == "PASS")
		_PASS();
	else if (this->_command == "NICK")
		_NICK();
	else if (this->_command == "USER")
		_USER();
	else if (this->_command == "QUIT")
		_QUIT();
	else if (this->_command == "JOIN")
		_JOIN();
	else if (this->_command == "PART")
		_PART();
	else if (this->_command == "MODE")
		_MODE();
	else if (this->_command == "TOPIC")
		_TOPIC();
	else if (this->_command == "INVITE")
		_INVITE();
	else if (this->_command == "KICK")
		_KICK();
	else if (this->_command == "PRIVMSG")
		_PRIVMSG();
	else if (this->_command == "NOTICE")
		_NOTICE();
	else if (this->_command == "PING")
		_PING();
	else if (this->_command == "PONG")
		_PONG();
	else if (this->_command == "WHO")
		_WHO();
	else
	{
		Logger::get()->log(this->_userNick + " tried executing the command " + this->_command + " which is not recognised by the server", WARNING);
		this->_response.clear();
		// this->_response = _draftErrorMessage(ERRNO_UNKNOWNCOMMAND, this->_fd, this->_userNick);
		this->_response = ":" + _server.getServerName() + " 421 " + this->_userNick + " " + this->_command + " :Unknown command\r\n";
		_server._sendToClient(this->_fd, this->_response);
	}
}

std::string	Message::_getErrorMessage(int errnum)
{
	if (errnum == ERRNO_NOSUCHNICK)
		return ERR_NOSUCHNICK;
	if (errnum == ERRNO_NOSUCHSERVER)
		return ERR_NOSUCHSERVER;
	if (errnum == ERRNO_NOSUCHCHANNEL)
		return ERR_NOSUCHCHANNEL;
	if (errnum == ERRNO_CANNOTSENDTOCHAN)
		return ERR_CANNOTSENDTOCHAN;
	if (errnum == ERRNO_TOOMANYCHANNELS)
		return ERR_TOOMANYCHANNELS;
	if (errnum == ERRNO_WASNOSUCHNICK)
		return ERR_WASNOSUCHNICK;
	if (errnum == ERRNO_TOOMANYTARGETS)
		return ERR_TOOMANYTARGETS;
	if (errnum == ERRNO_NOORIGIN)
		return ERR_NOORIGIN;
	if (errnum == ERRNO_NORECIPIENT)
		return ERR_NORECIPIENT;
	if (errnum == ERRNO_NOTEXTTOSEND)
		return ERR_NOTEXTTOSEND;
	if (errnum == ERRNO_NOTOPLEVEL)
		return ERR_NOTOPLEVEL;
	if (errnum == ERRNO_WILDTOPLEVEL)
		return ERR_WILDTOPLEVEL;
	if (errnum == ERRNO_UNKNOWNCOMMAND)
		return ERR_UNKNOWNCOMMAND;
	if (errnum == ERRNO_NOMOTD)
		return ERR_NOMOTD;
	if (errnum == ERRNO_NOADMININFO)
		return ERR_NOADMININFO;
	if (errnum == ERRNO_FILEERROR)
		return ERR_FILEERROR;
	if (errnum == ERRNO_NONICKNAMEGIVEN)
		return ERR_NONICKNAMEGIVEN;
	if (errnum == ERRNO_ERRONEUSNICKNAME)
		return ERR_ERRONEOUSNICKNAME;
	if (errnum == ERRNO_NICKNAMEINUSE)
		return ERR_NICKNAMEINUSE;
	if (errnum == ERRNO_NICKCOLLISION)
		return ERR_NICKCOLLISION;
	if (errnum == ERRNO_USERNOTINCHANNEL)
		return ERR_USERNOTINCHANNEL;
	if (errnum == ERRNO_NOTONCHANNEL)
		return ERR_NOTONCHANNEL;
	if (errnum == ERRNO_USERONCHANNEL)
		return ERR_USERNOCHANNEL;
	if (errnum == ERRNO_NOLOGIN)
		return ERR_NOLOGIN;
	if (errnum == ERRNO_SUMMONDISABLED)
		return ERR_SUMMONDISABLED;
	if (errnum == ERRNO_USERSDISABLED)
		return ERR_USERDISABLED;
	if (errnum == ERRNO_NOTREGISTERED)
		return ERR_NOTREGISTERED;
	if (errnum == ERRNO_NEEDMOREPARAMS)
		return ERR_NEEDMOREPARAMS;
	if (errnum == ERRNO_ALREADYREGISTERED)
		return ERR_ALREADYREGISTERED;
	if (errnum == ERRNO_NOPERMFORHOST)
		return ERR_NOPERMFORHOST;
	if (errnum == ERRNO_PASSWDMISMATCH)
		return ERR_PASSWDMISMATCH;
	if (errnum == ERRNO_YOURBANNEDCREEP)
		return ERR_YOURBANNEDCREEP;
	if (errnum == ERRNO_KEYSET)
		return ERR_KEYSET;
	if (errnum == ERRNO_CHANNELISFULL)
		return ERR_CHANNELISFULL;
	if (errnum == ERRNO_UNKNOWNMODE)
		return ERR_UNKNOWNMODE;
	if (errnum == ERRNO_INVITEONLYCHAN)
		return ERR_INVITEONLYCHAN;
	if (errnum == ERRNO_BANNEDFROMCHAN)
		return ERR_BANNEDFROMCHAN;
	if (errnum == ERRNO_BADCHANNELKEY)
		return ERR_BADCHANNELKEY;
	if (errnum == ERRNO_NOPRIVILEGES)
		return ERR_NOPRIVILEGES;
	if (errnum == ERRNO_CHANOPRIVSNEEDED)
		return ERR_CHANOPRIVSNEEDED;
	if (errnum == ERRNO_CANTKILLSERVER)
		return ERR_CANTKILLSERVER;
	if (errnum == ERRNO_NOOPERHOST)
		return ERR_NOOPERHOST;
	if (errnum == ERRNO_UMODEUNKNOWNFLAG)
		return ERR_UMODEUNKNOWNFLAG;
	if (errnum == ERRNO_USERSDONTMATCH)
		return ERR_USERSDONTMATCH;
	if (errnum == ERRNO_BADCHANNELMASK)
		return ERR_BADCHANNELMASK;
	return "Unknown Error Occured";
}
