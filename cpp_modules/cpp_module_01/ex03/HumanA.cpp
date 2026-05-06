/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:53:56 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 08:53:57 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack() const
{
    if (_weapon.getType().empty())
    {
        std::cout << _name << " Tried to attack without a weapon!!" << std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}