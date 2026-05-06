#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap default constructor called (no name give yet)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap constructor: Name: " << this->_name <<  " hit points: " << this->_hitPoints << " energy: " << this->_energyPoints << " attackdamage: " << this->_attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructed: Name: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor of ClapTrap called" << std::endl;
    *this = copy;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap operator(=) overload function called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string &target)
{
    if (!_isAlive())
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    else if (!_haveEnergy())
        std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints --;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= amount)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " took damage of " << amount << " hit points!" << std::endl;
    std::cout << "Hit Points remaining: " << this->_hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!_isAlive())
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    else if (!_haveEnergy())
        std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
    else
    {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " repaired for " << amount << " hit points!" << std::endl;
        this->_energyPoints--;
    }
}

bool    ClapTrap::_haveEnergy()
{
    return (this->_energyPoints > 0);
}

bool    ClapTrap::_isAlive()
{
    return (this->_hitPoints > 0);
}
