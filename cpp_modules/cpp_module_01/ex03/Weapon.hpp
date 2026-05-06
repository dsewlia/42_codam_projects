/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:54:37 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 08:54:38 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        const std::string &getType();
        void setType(std::string type);
};

#endif