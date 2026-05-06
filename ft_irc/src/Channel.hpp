/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Channel.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: driemers <driemers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/23 17:20:35 by driemers      #+#    #+#                 */
/*   Updated: 2025/07/21 14:24:27 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unordered_map>
#include "User.hpp"
// #include "Server.hpp"
#include <netinet/in.h>
#include <unordered_set>
#include <string>

class Server;

# define MAX_USER SOMAXCONN

class Channel {

	private:
		std::string				_name;
		std::unordered_set<int>	_members, _is_op, _pending_users; // client fds
		std::string				_topic;
		bool					_restrict_topic;
		std::string				_password;
		bool					_use_password;
		int						_users;
		bool					_is_inv_only;
		int						_user_limit;
		void addStatus(std::unordered_set<int> &set, int fd);
		void rmStatus(std::unordered_set<int> &set, int fd);
		bool hasStatus(std::unordered_set<int> &set, int fd);
	public:
		Channel();
		Channel(User& creator, const std::string &name, Server &server, std::string password = ""); // needs a server to add creato to _clientStates.joinedChannels.
		~Channel();
		std::unordered_set<int> &getOpList() {return _is_op;};

		void addMember(int fd);
		void removeMember(int fd);
		bool hasMember(int fd) const;
		bool isEmpty() const;
		std::string getChannelName() {return _name;};
		std::string getChannelTopic() {return _topic;};
		bool	isInviteFalgSet() {return _is_inv_only;};
		bool	isTopicFlagSet() {return _restrict_topic;};
		bool	isKeyFlagSet() {return _use_password;};
		int		getUserLimit() {return _user_limit;};
		std::string	getChannelKey() {return _password;};
		const std::unordered_set<int> &getMembers() const;

		inline Channel	&operator= (const Channel &other)
		{
			_name			= other._name;
			_members		= other._members;
			_is_op			= other._is_op;
			_pending_users	= other._pending_users;
			_topic			= other._topic;
			_restrict_topic	= other._restrict_topic;
			_password		= other._password;
			_use_password	= other._use_password;
			_users			= other._users;
			_is_inv_only	= other._is_inv_only;
			_user_limit		= other._user_limit;
			return (*this);
		}
		friend class Server;
};
