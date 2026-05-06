#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    ClapTrap::_name = _name + "_clap_name";
    this->_hitPoints = FragTrap::_initFTHitPoint;
    this->_energyPoints = ScavTrap::_initSTEnergyPoint;
    this->_attackDamage = FragTrap::_initFTAttackDamage;
    std::cout << "DiamondTrap default constructor called (no name give yet)" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hitPoints = FragTrap::_initFTHitPoint;
    this->_energyPoints = ScavTrap::_initSTEnergyPoint;
    this->_attackDamage = FragTrap::_initFTAttackDamage;
    std::cout << "DiamondTrap constructor: Name: " << this->_name << " hit points: " << this->_hitPoints << " energy: " << this->_energyPoints << " attackdamage: " << this->_attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructed: Name: " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    std::cout << "Copy constructor of DiamondTrap called" << std::endl;
    *this = copy;
}

DiamondTrap    &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap operator(=) overload function called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

// void    DiamondTrap::takeDamage(unsigned int amount)
// {
//     if (this->_hitPoints <= amount)
//     {
//         this->_hitPoints = 0;
//         std::cout << "DiamondTrap " << this->_name << "is dead!" << std::endl;
//         return ;
//     }
//     this->_hitPoints -= amount;
//     std::cout << "DiamondTrap " << this->_name << " took damage of " << amount << " hit points!" << std::endl;
//     std::cout << "Hit Points remaining: " << this->_hitPoints << std::endl;
// }

// void    DiamondTrap::beRepaired(unsigned int amount)
// {
//     if (!_isAlive())
//         std::cout << "DiamondTrap " << this->_name << " is dead!" << std::endl;
//     else if (!_haveEnergy())
//         std::cout << "DiamondTrap " << this->_name << " is out of energy!" << std::endl;
//     else
//     {
//         this->_hitPoints += amount;
//         std::cout << "DiamondTrap " << this->_name << " repaired for " << amount << " hit points!" << std::endl;
//         this->_energyPoints--;
//     }
// }

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << "\nClapTrap name: " << ClapTrap::_name << std::endl;
}
