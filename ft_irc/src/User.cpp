/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   User.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsewlia <dsewlia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 17:06:55 by root          #+#    #+#                 */
/*   Updated: 2025/07/23 17:22:38 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"
#include <sstream>

// Constructor
User::User() : _username(""), _nickname("") {}

// Destructor
User::~User() {}

// Set the username
void User::setUsername(const std::string& str) {
	_username = str;
}

// Set the nickname
void User::setNickname(const std::string& str) {
	_nickname = str;
}

void User::setRealname(const std::string& str) {
	_realname = str;
}

void User::setHostname(const std::string& str) {
	_hostname = str;
}

void User::setServername(const std::string& str) {
	_servername = str;
}

void	User::setPassword(const std::string& str) {
	_password = str;
}

void	User::setFd(const int fd) {
	_fd = fd;
}

// Get the username (const method)
const std::string& User::getUsername() const {
	return _username;
}

// Get the nickname (const method)
const std::string& User::getNickname() const {
	return _nickname;
}

const std::string& User::getRealname() const {
	return _realname;
}

const std::string& User::getHostname() const {
	return _hostname;
}

const std::string& User::getServername() const {
	return _servername;
}

const std::string& User::getPassword() const {
	return _password;
}

User User::createUser(int fd) {
	User user;
	// std::istringstream iss(buffer);
	// std::string username, hostname, servername, realname;
	
	user.setFd(fd);
	// Extract username and nickname from the buffer
	// iss >> username >> username >> hostname >> servername >> realname;
	// Set the username and nickname in the User object
	user.setPassword("");
	user.setNickname("*");
	user.setUsername("");
	user.setHostname("");
	user.setServername("ircserv");
	user.setRealname("");

	return user;
}
