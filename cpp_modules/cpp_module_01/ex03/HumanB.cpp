/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:54:13 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 17:30:14 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name)
{
    _weapon = NULL;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void    HumanB::attack() const
{
    if (!_weapon || _weapon->getType().empty())
    {
        std::cout << _name << " tried to attack without a weapon" << std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}