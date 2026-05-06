/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 15:42:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/21 14:26:07 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // needed for structs like sockadd_in/in_addr
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>
#include <iostream>
#include "Server.hpp" 
#include "Logger.hpp"

int main (int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "Usage: ./irc_server <port> <password>\n";
		return 1;
	}

	int port = std::stoi(argv[1]);
	std::string password = argv[2];
	
	try {
		Server server(port, password);
		server.run();  // starts poll() loop
	} catch (const std::exception& e) {
		std::cerr << "Server error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
