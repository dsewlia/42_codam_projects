#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class   ScavTrap : virtual public ClapTrap
{
    protected:
		static unsigned int	_initSTHitPoint;
		static unsigned int	_initSTEnergyPoint;
		static unsigned int	_initSTAttackDamage;

	public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();

        ScavTrap            &operator=(const ScavTrap &rhs);
        virtual void        attack(const std::string &target);
        // void        takeDamage(unsigned int amount);
        // void        beRepaired(unsigned int amount);
        void        guardGate();
};

#endif