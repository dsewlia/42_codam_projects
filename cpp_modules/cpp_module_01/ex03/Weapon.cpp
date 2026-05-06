/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:54:31 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 08:54:34 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
    return (_type);
}

void    Weapon::setType(std::string type)
{
    _type = type;
}
