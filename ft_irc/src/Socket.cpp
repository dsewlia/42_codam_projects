/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:15:29 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/23 09:29:22 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"
#include <fcntl.h>

Socket::Socket(int port): _port(port)
{
	_sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_sockFd < 0)
	{
		perror("socket");
		throw std::runtime_error("Fail to start socket");
	}
	int option = 1;
	if(setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) || \
	setsockopt(_sockFd, SOL_SOCKET, SO_REUSEPORT, &option, sizeof(option)))
	{
		perror("setsocketopt");
		throw std::runtime_error("Fail to set socket options");
	}
	fcntl(_sockFd, F_SETFL, O_NONBLOCK); // Set the socket to non-blocking mode
	sockInfo(_port);
	sockBind();
	sockListen();
}

Socket::~Socket()
{
	close(_sockFd);
	std::cout << "Server Socket closed" << std::endl;
}

void	Socket::sockInfo(int port)
{
	_sockAddr.sin_family = AF_INET;
	_sockAddr.sin_addr.s_addr = INADDR_ANY; // bind to all interfaces
	_sockAddr.sin_port = htons(port);
}

void	Socket::sockBind(void)
{
	if (bind(_sockFd, reinterpret_cast<sockaddr*>(&_sockAddr), sizeof(_sockAddr)))
	{
		perror("bind");
		throw std::runtime_error("Fail to bind socket");
	}
}

int		Socket::sockListen(void)
{
	int listenerr = listen(_sockFd, SOMAXCONN);
	if (listenerr == -1)
	{
		perror("listen");
		throw std::runtime_error("Fail to listen to socket");
	}
	return listenerr;
}

std::pair<int, ClientInfo>	Socket::sockAccept(void)
{
	ClientInfo info;
	socklen_t clientAddrLen = sizeof(info.clientAddr);
	int client_fd = accept(_sockFd, reinterpret_cast<sockaddr*>(&info.clientAddr), &clientAddrLen);
	if (client_fd < 0) {
		perror("accept");
		throw std::runtime_error("Failed to accept connection");
	}
	std::cout << "socket fd in accept" << client_fd << std::endl;
	_clients[client_fd] = info;

	return {client_fd, info};
}

void	Socket::sockSend(const int &fd, const std::string &text)
{
	int byteCount = send(fd, text.c_str(), text.length(), MSG_NOSIGNAL);
	if (byteCount < 0)
	{
		perror("send");
		throw std::runtime_error("User -> " + std::to_string(fd) + " timeout before message send");
	}
}

int		Socket::getFd(void) {
	return _sockFd;
}