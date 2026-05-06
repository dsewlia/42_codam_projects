/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:24:48 by dsewlia           #+#    #+#             */
/*   Updated: 2025/07/19 22:25:38 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "Channel.hpp"
#include "defines.hpp"
#include <bits/stdc++.h>
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

#define	ARG_MAX 14

class Server;
class Channel;

typedef	struct	s_channelKey
{
	std::string	channelName;
	std::string	key;
}	t_channelKey;

class	Message
{
	private:
			std::string					_userNick;
			std::string					_prefix;
			std::string					_command;
			std::vector<std::string>	_param;
			std::string					_response;
			int							_fd;
			Server						&_server;
			std::unordered_map<std::string, Channel> &_channels;
			struct Clientstate			*_userState;
			std::string					_trailing;
			std::vector<std::string>	_target;
			std::vector<struct Clientstate> _targetState;
			std::vector<bool>			_targetFound;
			bool						_criticalError;


			void	_PASS(void);
			void	_NICK(void);
			void	_USER(void);
			void	_QUIT(void);
			void	_JOIN(void);
			void	_PART(void);
			void	_MODE(void);
			void	_TOPIC(void);
			void	_INVITE(void);
			void	_KICK(void);
			void	_PRIVMSG(void);
			void	_NOTICE(void);
			void	_PING(void);
			void	_PONG(void);
			void	_WHO(void);

			//helper functions
			bool		_checkChannelName(const std::string &name);
			bool		_checkNickName(const std::string &name);
			Channel*	_getChannel(std::string name);
			void		_updateTargetList(std::string targets);
			bool		_channelExists(std::string channelName);
			bool		_userExists(std::string userName);
			bool		_channelHasUser(int targetFd, std::string channelName);
			std::string	_getErrorMessage(int errnum);
			std::string	_getClientNick(int fd);
			int			_getClientFd(std::string targetNick);
			std::string	_draftErrorMessage(int errnum, int targetFd, std::string targetNick);
			
	public:
			Message(std::string &msg, int fd, Server &server);
			~Message();
			void		executeCommand(void);
};
