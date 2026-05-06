#include "ScavTrap.hpp"

unsigned int	ScavTrap::_initSTHitPoint = 100;
unsigned int	ScavTrap::_initSTEnergyPoint = 50;
unsigned int	ScavTrap::_initSTAttackDamage = 20;

ScavTrap::ScavTrap()
{
    this->_hitPoints = _initSTHitPoint;
    this->_energyPoints = _initSTEnergyPoint;
    this->_attackDamage = _initSTAttackDamage;
    std::cout << "ScavTrap default constructor called (no name give yet)" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_hitPoints = _initSTHitPoint;
    this->_energyPoints = _initSTEnergyPoint;
    this->_attackDamage = _initSTAttackDamage;
    std::cout << "ScavTrap constructor: Name: " << this->_name <<  " hit points: " << this->_hitPoints << " energy: " << this->_energyPoints << " attackdamage: " << this->_attackDamage << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructed: Name: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "Copy constructor of ScavTrap called" << std::endl;
    *this = copy;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "ScavTrap operator(=) overload function called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

void    ScavTrap::attack(const std::string &target)
{
    if (!_isAlive())
        std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
    else if (!_haveEnergy())
        std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints --;
    }
}

// void    ScavTrap::takeDamage(unsigned int amount)
// {
//     if (this->_hitPoints <= amount)
//     {
//         this->_hitPoints = 0;
//         std::cout << "ScavTrap " << this->_name << "is dead!" << std::endl;
//         return ;
//     }
//     this->_hitPoints -= amount;
//     std::cout << "ScavTrap " << this->_name << " took damage of " << amount << " hit points!" << std::endl;
//     std::cout << "Hit Points remaining: " << this->_hitPoints << std::endl;
// }

// void    ScavTrap::beRepaired(unsigned int amount)
// {
//     if (!_isAlive())
//         std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
//     else if (!_haveEnergy())
//         std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
//     else
//     {
//         this->_hitPoints += amount;
//         std::cout << "ScavTrap " << this->_name << " repaired for " << amount << " hit points!" << std::endl;
//         this->_energyPoints--;
//     }
// }

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << "is in Gate keeper mode" << std::endl;
}