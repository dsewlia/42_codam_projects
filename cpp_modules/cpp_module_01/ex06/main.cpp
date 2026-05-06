/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:33:15 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 17:14:59 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harp.hpp"
#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string	temp;
	Harl		harl;

	if (argc != 2)
	{
		std::cout << "Argument mistach\nPlease enter one argument <level>" << std::endl;
		return (0);
	}
	temp = argv[1];
	harl.complain(temp);
	return (0);
}
