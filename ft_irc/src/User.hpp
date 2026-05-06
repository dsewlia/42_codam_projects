/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   User.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsewlia <dsewlia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 14:08:34 by driemers      #+#    #+#                 */
/*   Updated: 2025/07/23 17:20:14 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

// This class will repersent a known user.
// Everything that we will need to know about a user sould be stored in here.
// when a unkown user joins, a new instance of this class sould be made.
class User
{
private:
	std::string	_username;
	std::string	_hostname;
	std::string	_servername;
	std::string	_realname;
	std::string	_nickname;
	std::string _password;
	int			_fd;
public:
	User();
	~User();

	void					setUsername(const std::string& str);
	void					setNickname(const std::string& str);
	void					setRealname(const std::string& str);
	void					setHostname(const std::string& str);
	void					setPassword(const std::string& str);
	void					setServername(const std::string& str);
	void					setFd(const int fd);
	const std::string&		getUsername() const;
	const std::string&		getNickname() const;
	const std::string&		getRealname() const;
	const std::string&		getHostname() const;
	const std::string&		getPassword() const;
	const std::string&		getServername() const;

	static User				createUser(int fd);
	inline int				getFd() const { return(_fd); };
};

