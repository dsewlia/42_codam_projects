#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class   FragTrap : public ClapTrap
{
    private:

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();

        FragTrap            &operator=(const FragTrap &rhs);
        void        attack(const std::string &target) override;
        // void        takeDamage(unsigned int amount) override;
        // void        beRepaired(unsigned int amount) override;
        void        highFiveGuys();
};

#endif