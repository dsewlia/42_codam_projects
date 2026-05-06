#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FrapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class   DiamondTrap :  public FragTrap, public ScavTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();

        DiamondTrap            &operator=(const DiamondTrap &rhs);
        void        attack(const std::string &target) override;
        // void        takeDamage(unsigned int amount);
        // void        beRepaired(unsigned int amount);
        void        whoAmI();
};

#endif