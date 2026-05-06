/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:18:18 by jovieira          #+#    #+#             */
/*   Updated: 2025/07/14 14:15:12 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define BUFFERS_SIZE 1024

#define DEBUG_MODE false
//For channel and nick name lengths
#define MAX_CHANNEL_LENGTH 50
#define MAX_NICK_LENGTH 30
//Error reply definitions
#define	ERRNO_NOSUCHNICK 401
#define	ERR_NOSUCHNICK " :No such nick/channel" //pre: <nick>
#define	ERRNO_NOSUCHSERVER 402
#define	ERR_NOSUCHSERVER " :No such server" //pre: <server>
#define	ERRNO_NOSUCHCHANNEL 403
#define	ERR_NOSUCHCHANNEL " :No such channel" //pre: <channel>
#define	ERRNO_CANNOTSENDTOCHAN 404
#define	ERR_CANNOTSENDTOCHAN " :Cannot send to channel" //pre: <channel>
#define	ERRNO_TOOMANYCHANNELS 405
#define	ERR_TOOMANYCHANNELS " :You have joined too many channels" //pre: <channel>
#define	ERRNO_WASNOSUCHNICK 406
#define	ERR_WASNOSUCHNICK " :There was no such nickname" //pre: <nick>
#define	ERRNO_TOOMANYTARGETS 407
#define	ERR_TOOMANYTARGETS " :Duplicate recipients. No message delivered" //post: <target>
#define	ERRNO_NOORIGIN 409
#define	ERR_NOORIGIN ":No origin specified"
#define	ERRNO_NORECIPIENT 411
#define	ERR_NORECIPIENT ":No recipient given " //post: <command>
#define	ERRNO_NOTEXTTOSEND 412
#define	ERR_NOTEXTTOSEND ":No text to send"
#define	ERRNO_NOTOPLEVEL 413
#define	ERR_NOTOPLEVEL " :No toplevel domain specified" //pre: <mask>
#define	ERRNO_WILDTOPLEVEL 414
#define	ERR_WILDTOPLEVEL " :Wildcare n toplevel domain" //pre: <mask>
#define	ERRNO_UNKNOWNCOMMAND 421
#define	ERR_UNKNOWNCOMMAND " :Unknown command" //pre: <command>
#define	ERRNO_NOMOTD 422
#define	ERR_NOMOTD ":MOTD File is missing"
#define	ERRNO_NOADMININFO 423
#define	ERR_NOADMININFO " :No administrative info available" //pre: <server>
#define	ERRNO_FILEERROR 424
#define	ERR_FILEERROR ":File error doing " //post: <file op> on <file>
#define	ERRNO_NONICKNAMEGIVEN 431
#define	ERR_NONICKNAMEGIVEN ":No nickname given"
#define	ERRNO_ERRONEUSNICKNAME 432
#define	ERR_ERRONEOUSNICKNAME " :Erroneus nickname" //pre: <nick>
#define	ERRNO_NICKNAMEINUSE 433
#define	ERR_NICKNAMEINUSE " :Nickname is already in use" //pre: <nick>
#define	ERRNO_NICKCOLLISION 436
#define	ERR_NICKCOLLISION " :Nickname collision KILL" //pre: <nick>
#define	ERRNO_USERNOTINCHANNEL 441
#define	ERR_USERNOTINCHANNEL " :They aren't on that channel" //pre: <nick> <channel>
#define	ERRNO_NOTONCHANNEL 442
#define	ERR_NOTONCHANNEL " :You're not on that channel" //pre: <channel>
#define	ERRNO_USERONCHANNEL 443
#define	ERR_USERNOCHANNEL " :is already on channel" //pre: <user> <channel>
#define	ERRNO_NOLOGIN 444
#define	ERR_NOLOGIN " :User not logged in" //pre: <user>
#define	ERRNO_SUMMONDISABLED 445
#define	ERR_SUMMONDISABLED ":SUMMON has been disabled"
#define	ERRNO_USERSDISABLED 446
#define	ERR_USERDISABLED ":USERS has been disabled"
#define	ERRNO_NOTREGISTERED 451
#define	ERR_NOTREGISTERED ":You have not registered"
#define	ERRNO_NEEDMOREPARAMS 461
#define	ERR_NEEDMOREPARAMS " :Not enough parameters" //pre: <command>
#define	ERRNO_ALREADYREGISTERED 462
#define	ERR_ALREADYREGISTERED ":You may not reregister"
#define	ERRNO_NOPERMFORHOST 463
#define	ERR_NOPERMFORHOST ":You host isn't among the privileged"
#define	ERRNO_PASSWDMISMATCH 464
#define	ERR_PASSWDMISMATCH ":Password incorrect"
#define	ERRNO_YOURBANNEDCREEP 465
#define	ERR_YOURBANNEDCREEP ":You are banned from this server"
#define	ERRNO_KEYSET 467
#define	ERR_KEYSET " :Channel key already set" //pre: <channel>
#define	ERRNO_CHANNELISFULL 471
#define	ERR_CHANNELISFULL " :Cannot join channel (+l)" //pre: <channel>
#define	ERRNO_UNKNOWNMODE 472
#define	ERR_UNKNOWNMODE " :is unknown mode char to me" //pre: <char>
#define	ERRNO_INVITEONLYCHAN 473
#define	ERR_INVITEONLYCHAN " :Cannot join channel (+i)" //pre: <channel>
#define	ERRNO_BANNEDFROMCHAN 474
#define	ERR_BANNEDFROMCHAN " :Cannot join channel (+b)" //pre: <channel>
#define	ERRNO_BADCHANNELKEY 475
#define	ERR_BADCHANNELKEY " :Cannot join channel (+k)" //pre: <channel>
#define	ERRNO_BADCHANNELMASK 476
#define ERR_BADCHANNELMASK " :Bad channel mask"
#define	ERRNO_NOPRIVILEGES 481
#define	ERR_NOPRIVILEGES ":Permission Denied- You're not an IRC operator"
#define	ERRNO_CHANOPRIVSNEEDED 482
#define	ERR_CHANOPRIVSNEEDED " :You're not channel operator" //pre: <channel>
#define	ERRNO_CANTKILLSERVER 483
#define	ERR_CANTKILLSERVER ":You cant kill a server!"
#define	ERRNO_NOOPERHOST 491
#define	ERR_NOOPERHOST ":No O-lines for your host"
#define	ERRNO_UMODEUNKNOWNFLAG 501
#define	ERR_UMODEUNKNOWNFLAG ":Unknown MODE flag"
#define	ERRNO_USERSDONTMATCH 502
#define	ERR_USERSDONTMATCH ":Cant change modes for other users"
