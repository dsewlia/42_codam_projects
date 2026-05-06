/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:33:15 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 17:00:03 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harp.hpp"
#include <iostream>
#include <cctype>

bool	check_cin(void)
{
	if (std::cin.eof())
	{
		std::cin.clear();
		freopen("/dev/tty", "r", stdin);
		std::cout << "\nCritical input deducted (ctrl + D), please avoid" << std::endl;
		return (true);
	}
	return (false);
}

int	main()
{
	std::string	temp;
	Harl		harl;

	while (true)
	{
		std::cout << "\nLevels: DEBUG | INFO | WARNING | ERROR\nNote: If you are tired of hearing to Harp, please type EXIT to get out" << std::endl;
		temp.clear();
		std::getline(std::cin, temp);
		if (check_cin())
			continue ;
		if (temp == "EXIT")
		{
			std::cout << "\nSee you later!\n" << std::endl;
			break;
		}
		harl.complain(temp);
	}
	return (0);
}