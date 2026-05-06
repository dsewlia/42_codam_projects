#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap
{
    protected:
        std::string _name;
        unsigned int         _hitPoints;
        unsigned int         _energyPoints;
        unsigned int         _attackDamage;
		static unsigned int	_initCTHitPoint;
		static unsigned int	_initCTEnergyPoint;
		static unsigned int	_initCTAttackDamage;

        bool        _haveEnergy();
        bool        _isAlive();

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();

        ClapTrap    &operator=(const ClapTrap &rhs);
        virtual void        attack(const std::string &target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif
