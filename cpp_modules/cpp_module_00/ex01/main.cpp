/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:11:50 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 14:36:08 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cctype"
#include "Phonebook.hpp"

bool	check_cin(void)
{
	if (std::cin.eof())
	{
		std::cin.clear();
		freopen("/dev/tty", "r", stdin);
		std::cout << "Critcal input deducted (ctrl + D), please avoid" << std::endl;
		std::cout << std::endl;
		return (true);
	}
	return (false);
}

int main()
{
    Phonebook   phonebook = Phonebook();

    return (0);
}