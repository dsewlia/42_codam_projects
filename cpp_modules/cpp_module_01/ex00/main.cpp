/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:34:11 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/22 21:39:32 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "Zombie Foo created using randomChump" << std::endl;
    randomChump("Foo");
    
    std::cout << "Zombie Bar created using newZombie" << std::endl;
    Zombie *zombie = newZombie("Bar");
    zombie->announce();
    delete zombie;
    return (0);
}