/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsewlia <dsewlia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 09:51:10 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/21 14:29:43 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <iostream>
#include <exception>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unordered_map>

struct	ClientInfo{
	sockaddr_in clientAddr;
};

class Socket{

	private:
		int			_sockFd;
		int			_port;
		sockaddr_in _sockAddr;
		std::unordered_map<int, ClientInfo> _clients;
	
	public:
		Socket(int port);
		~Socket();

		void	sockInfo(int port);
		void	sockBind(void);
		int		sockListen(void);
		std::pair<int, ClientInfo> sockAccept(void);
		void	sockSend(const int &fd, const std::string &text);

		int		getFd(void);
		const std::unordered_map<int, ClientInfo>& getClients() const {return _clients;}
};
