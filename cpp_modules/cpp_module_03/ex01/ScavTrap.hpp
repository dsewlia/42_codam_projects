#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class   ScavTrap : public ClapTrap
{
    private:

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();

        ScavTrap            &operator=(const ScavTrap &rhs);
        void        attack(const std::string &target) override;
        // void        takeDamage(unsigned int amount);
        // void        beRepaired(unsigned int amount);
        void        guardGate();
};

#endif