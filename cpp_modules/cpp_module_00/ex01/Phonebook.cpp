/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:45:02 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 14:45:47 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	Phonebook::_count = 0;

bool	check_cin(void);

Phonebook::Phonebook(void)
{
    std::string query;
    std::cout << "Welcome!!\n";
    while (true)
    {
        std::cout << "Type ADD to add a contact\nType SEARCH to search a contact\nType EXIT to exit" << std::endl;
        query.clear();
        std::getline(std::cin, query);
        if (check_cin())
			continue ;
		else if (query == "ADD")
        {
            _ADD();
        }
        else if (query == "SEARCH")
        {
            _SEARCH();
        }
        else if (query == "EXIT")
        {
            _EXIT();
            return ;
        }
        else
        {
            std::cout << "Command not found\n" << std::endl;
        }
        std::cout << std::endl;
    }
}

std::string Phonebook::_formatter(std::string str)
{
    std::string value;

    if (str.size() > 10)
    {
        for (int i = 0; i < 9; i++)
        {
            value += str[i];
        }
        value += '.';
        return (value);
    }
    else
    {
        value = str;
        for (unsigned long i = 0; i < 10 - str.size(); i++)
        {
            value = ' ' + value;
        }
        return (value);
    }
}

void    Phonebook::_ADD(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    
	//First Name parsing
	while (true)
	{
		firstName.clear();
		std::cout << "First Name: ";
		std::getline(std::cin, firstName);
		if (check_cin())
			continue;
		else if (firstName.empty())
		{
			std::cout << "No input given, please try again\n" << std::endl;
			continue ;
		}
		else
			break ;
	}
	//Last Name parsing
	while (true)
	{
		lastName.clear();
		std::cout << "Last Name: ";
		std::getline(std::cin, lastName);
		if (check_cin())
			continue;
		else if (lastName.empty())
		{
			std::cout << "No input given, please try again\n" << std::endl;
			continue ;
		}
		else
			break ;
	}
	//Nick Name parsing
	while (true)
	{
		nickName.clear();
		std::cout << "Nick Name: ";
		std::getline(std::cin, nickName);
		if (check_cin())
			continue;
		else if (nickName.empty())
		{
			std::cout << "No input given, please try again\n" << std::endl;
			continue ;
		}
		else
			break ;
	}
	//Phone Number parsing
    while (true)
    {
		phoneNumber.clear();
        unsigned long i;
        while (true)
		{
			phoneNumber.clear();
			std::cout << "Phone Number: ";
			std::getline(std::cin, phoneNumber);
			if (check_cin())
				continue;
			else if (phoneNumber.empty())
			{
				std::cout << "No input given, please try again\n" << std::endl;
				continue ;
			}
			else
				break ;
		}
        for (i = 0; i < phoneNumber.size(); i++)
        {
            if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
            {
                std::cout << "Non numberic value deducted. please enter the number again\n" << std::endl;
                break ;
            }     
        }
        if (i == phoneNumber.size())
            break ;
    }
	//Darkest Secret parsing
	while (true)
	{
		darkestSecret.clear();
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkestSecret);
		if (check_cin())
			continue;
		else if (darkestSecret.empty())
		{
			std::cout << "No input given, please try again\n" << std::endl;
			continue ;
		}
		else
			break ;
	}
    Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    if (_count >= 8)
	{
		for (int i = 0; i < 7; i++)
		{
			_contacts[i] = _contacts[i + 1];
		}
		_contacts[7].clear();
		_count--;
	}
    _contacts[_count] = contact;
	_count++;
}

void    Phonebook::_SEARCH(void)
{
	std::string		searchIndex;
	int				index = 0;

    if (_count == 0)
    {
        std::cout << "No contacts are stored in the phonebook\n" << std::endl;
        return ;
    }
    std::cout << _formatter("Index") << "|" << _formatter("First Name") << "|" << _formatter("Last Name") << "|" << _formatter("Nick Name") << std::endl;
    for (int i = 1; i <= _count; i++)
    {
        std::cout << "         " << i << "|" << _formatter(_contacts[i - 1].getFirstName()) << "|" << _formatter(_contacts[i - 1].getLastName()) << "|" << _formatter(_contacts[i - 1].getNickName()) << std::endl;
    }
	//Index parsing
	while (true)
	{
		searchIndex.clear();
		std::cout << "Please enter the index of the contacts you want to search\nEnter 0 to redirect to the main menu" << std::endl;
		std::getline(std::cin, searchIndex);
		if (check_cin())
			continue;
		else if (searchIndex.empty())
		{
			std::cout << "No input given, please try again\n" << std::endl;
			continue ;
		}
		else
		{
			unsigned long i;
			for (i = 0; i < searchIndex.size(); i++)
			{
				if (searchIndex[i] < '0' || searchIndex[i] > '9')
				{
					std::cout << "Invalid input, please try again\n" << std::endl;
					break ;
				}
			}
			if (i == searchIndex.size())
			{
				index = atoi(&searchIndex[0]);
				if (index == 0)
					return ;
				else if (index < 0 || index > _count)
				{
					std::cout << "The index is out of bounds\n" << std::endl;
					continue ;
				}
				else
					break ;
			}
		}
	}
    std::cout << "First Name: " << _contacts[index - 1].getFirstName() << "\n";
    std::cout << "Last Name " << _contacts[index - 1].getLastName() << "\n";
    std::cout << "Nick Name: " << _contacts[index - 1].getNickName() << "\n";
    std::cout << "Phone Number: " << _contacts[index - 1].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << _contacts[index - 1].getDarkestSecret() << "\n";
	std::cout << std::endl;

}

void    Phonebook::_EXIT(void)
{
    std::cout << "See you later!!\n" << std::endl;
}