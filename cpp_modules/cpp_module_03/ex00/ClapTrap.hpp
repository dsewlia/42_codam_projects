#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap
{
    private:
        std::string _name;
        unsigned int         _hitPoints;
        unsigned int         _energyPoints;
        unsigned int         _attackDamage;

        bool        _haveEnergy();
        bool        _isAlive();

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();

        ClapTrap    &operator=(const ClapTrap &rhs);
        void        attack(const std::string &target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif
