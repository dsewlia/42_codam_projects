/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:54:04 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 08:54:07 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;

    public:
        void    attack() const;
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
};
