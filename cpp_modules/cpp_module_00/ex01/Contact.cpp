/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:39:41 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 14:44:39 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickName = nickName;
    this->_phoneNumber = phoneNumber;
    this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void)
{
    return (this->_firstName);
}

std::string Contact::getLastName(void)
{
    return (this->_lastName);
}

std::string Contact::getNickName(void)
{
    return (this->_nickName);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

void	Contact::clear()
{
	_firstName.clear();
	_lastName.clear();
	_nickName.clear();
	_phoneNumber.clear();
	_darkestSecret.clear();
}
