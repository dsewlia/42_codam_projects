#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class   FragTrap : virtual public ClapTrap
{
    protected:
		static unsigned int	_initFTHitPoint;
		static unsigned int	_initFTEnergyPoint;
		static unsigned int	_initFTAttackDamage;

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();

        FragTrap            &operator=(const FragTrap &rhs);
        virtual void        attack(const std::string &target) override;
        // void        takeDamage(unsigned int amount) override;
        // void        beRepaired(unsigned int amount) override;
        void        highFiveGuys();
};

#endif