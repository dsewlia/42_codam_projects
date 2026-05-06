/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:53:50 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 08:54:19 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class   HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon;

    public:
        void    setWeapon(Weapon &weapon);
        void    attack() const;
        HumanB(std::string name);
        ~HumanB();
};
