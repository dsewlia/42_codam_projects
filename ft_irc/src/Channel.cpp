/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:02:03 by driemers          #+#    #+#             */
/*   Updated: 2025/07/16 13:38:15 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "User.hpp"
#include "Server.hpp"

void	Channel::addMember(int fd) {
	_members.insert(fd);
}

void	Channel::removeMember(int fd) {
	_members.erase(fd);
	_is_op.erase(fd);
	_pending_users.erase(fd);
}

bool	Channel::hasMember(int fd) const {
	return _members.find(fd) != _members.end();
}

bool	Channel::isEmpty() const {
	return _members.empty();
}

const	std::unordered_set<int>& Channel::getMembers() const {
	return _members;
}

void Channel::addStatus(std::unordered_set<int> &set, int fd)
{
	set.insert(fd);
}
void Channel::rmStatus(std::unordered_set<int> &set, int fd)
{
	set.erase(fd);
}

bool Channel::hasStatus(std::unordered_set<int> &set, int fd)
{
	if (set.find(fd) != set.end())
		return (true);
	return (false);
}

Channel::Channel()
	:	_name("default"),
		_members({}),
		_is_op({}),
		_pending_users({{}}),
		_topic(""),
		_restrict_topic(false),
		_password(""),
		_use_password(false),
		_users(1),
		_is_inv_only(false),
		_user_limit(MAX_USER)
{
}

Channel::Channel(User& creator, const std::string &name, Server &server, std::string password)
	:	_name(name),
		_members({creator.getFd()}),
		_is_op({creator.getFd()}), // adds creator to op. (bit hacky makig creator op before adding but i think it should be fine.)
		_pending_users({{}}),
		_topic(""),
		_restrict_topic(false),
		_password(""),
		_use_password(false),
		_users(1),
		_is_inv_only(false),
		_user_limit(MAX_USER)
{
	server.userJoin(*this, creator, NULL);
	if (password != "")
	{
		_password		= password;
		_use_password	= true;
	}
}
Channel::~Channel()
{
}
