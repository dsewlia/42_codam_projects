/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:30:03 by jovieira          #+#    #+#             */
/*   Updated: 2025/07/16 15:54:58 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Channel.hpp"


// int Server::removeUserToClientState(const User &user)
// {
// 	_clientStates.erase(user.getFd());
// }

int	Server::isOp(Channel& c, User& user)
{
	if (c.hasMember(user.getFd()) == false)
		return (ERRNO_NOTONCHANNEL);
	if (c.hasStatus(c._is_op, user.getFd()) == false)
		return (ERRNO_CHANOPRIVSNEEDED); // need op
	return (0);
}

// internal fuction SOULD NOT BE CALLED OUTSIDE COMMANDS!
// use one of these instead: userJoin, userAcceptInvite, inviteUser.
int	Server::addUser(Channel& c, User& user)
{
	if (c.hasMember(user.getFd()) == true)
		return (ERRNO_USERONCHANNEL); // already in channel
	if (c._users >= c._user_limit)
		return (ERRNO_CHANNELISFULL); // channel full
	if (c.hasStatus(c._pending_users ,user.getFd()) == false && c._is_inv_only == true)
		return (ERRNO_INVITEONLYCHAN); // you are not invited
	c.addMember(user.getFd());
	// assuming the rest of the code makes sure there are no duplicate fds.
	_clientStates[user.getFd()].joinedChannels.insert(_clientStates[user.getFd()].joinedChannels.end(), c.getChannelName());
	c._users++;
	return (0);
}

int	Server::userSendMessage(Channel& c, User& user, std::string& message)
{
	if (c.hasMember(user.getFd()) == false)
		return (ERRNO_NOTONCHANNEL); // not in channel
	// write message into file fd.
	(void) message;
	return (0);
}

int	Server::userAcceptInvite(Channel& c, User& user)
{
	int err = addUser(c, user);
	if (err != 0)
		return (err);
	c._pending_users.erase(user.getFd());
	return (0);
}

// pass can be NULL if there is no password required.
int	Server::userJoin(Channel& c, User& user, std::string *pass)
{
	if (c._use_password == true)
	{
		if (pass == NULL)
			return (ERRNO_BADCHANNELKEY); // need password
		if (c._password != *pass)
			return (ERRNO_BADCHANNELKEY); // incorrect password
	}
	if (c._is_inv_only)
		return (userAcceptInvite(c, user));
	return (addUser(c, user));
}

int	Server::inviteUser(Channel& c, User& user, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	if (c.hasStatus(c._pending_users, user.getFd()) == true ||
		c.hasStatus(c._members, user.getFd()) == true)
		return (ERRNO_USERONCHANNEL); // already here or invited
	c.addStatus(c._pending_users, user.getFd());
	return (0);
}

int	Server::kickUser(Channel& c, User& user, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	if (c.hasMember(user.getFd()) == false)
		return (ERRNO_USERNOTINCHANNEL); // user not in channel
	c.removeMember(user.getFd());
	_clientStates[user.getFd()].joinedChannels.erase(c.getChannelName());
	c._users--;

	return (0);
}

int	Server::setTopic(Channel& c, std::string& topic, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0 && c._restrict_topic)
		return (isop);
	c._topic = topic;
	return (0);
}

int	Server::modeI(Channel& c, bool is_inv, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	c._is_inv_only = is_inv;
	return (0);
}
int	Server::modeT(Channel& c, bool retrict, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	c._restrict_topic = retrict;
	return (0);
}

// new_pass can be NULL if has pass is false
int	Server::modeK(Channel& c, bool has_pass, std::string *new_pass, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	if (has_pass == true && new_pass == NULL)
		return (ERRNO_NEEDMOREPARAMS); // need key
	c._use_password = has_pass;
	if (has_pass == true)
		c._password = *new_pass;
	return (0);
}

int	Server::modeO(Channel& c, bool set_op, User &user, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	if (c.hasMember(user.getFd()) == false)
		return (ERRNO_NOSUCHNICK); // user not in channel
	if (set_op == false)
	{
		c.rmStatus(c._is_op, user.getFd());
		return (0);
	}
	c.addStatus(c._is_op, user.getFd());
	return (0);
}

int	Server::modeL(Channel& c, bool has_limit, int new_limit, User& op)
{
	int	isop = isOp(c, op);

	if (isop != 0)
		return (isop);
	if (has_limit == false)
	{
		c._user_limit = MAX_USER;
		return (0);
	}
	if (new_limit > MAX_USER || new_limit <= 1)
		return (ERRNO_UMODEUNKNOWNFLAG); // invalid limit ???
	c._user_limit = new_limit;
	return (0);
}
