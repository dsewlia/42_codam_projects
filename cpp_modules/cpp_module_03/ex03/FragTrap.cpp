#include "FrapTrap.hpp"

unsigned int	FragTrap::_initFTHitPoint = 100;
unsigned int	FragTrap::_initFTEnergyPoint = 100;
unsigned int	FragTrap::_initFTAttackDamage = 30;

FragTrap::FragTrap()
{
    this->_hitPoints = _initFTHitPoint;
    this->_energyPoints = _initFTEnergyPoint;
    this->_attackDamage = _initFTAttackDamage;
    std::cout << "FragTrap default constructor called (no name give yet)" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = _initFTHitPoint;
    this->_energyPoints = _initFTEnergyPoint;
    this->_attackDamage = _initFTAttackDamage;
    std::cout << "FragTrap constructor: Name: " << this->_name <<  " hit points: " << this->_hitPoints << " energy: " << this->_energyPoints << " attackdamage: " << this->_attackDamage << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructed: Name: " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "Copy constructor of FragTrap called" << std::endl;
    *this = copy;
}

FragTrap    &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap operator(=) overload function called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

void    FragTrap::attack(const std::string &target)
{
    if (!_isAlive())
        std::cout << "FragTrap " << this->_name << " is dead!" << std::endl;
    else if (!_haveEnergy())
        std::cout << "FragTrap " << this->_name << " is out of energy!" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints --;
    }
}

// void    FragTrap::takeDamage(unsigned int amount)
// {
//     if (this->_hitPoints <= amount)
//     {
//         this->_hitPoints = 0;
//         std::cout << "FragTrap " << this->_name << "is dead!" << std::endl;
//         return ;
//     }
//     this->_hitPoints -= amount;
//     std::cout << "FragTrap " << this->_name << " took damage of " << amount << " hit points!" << std::endl;
//     std::cout << "Hit Points remaining: " << this->_hitPoints << std::endl;
// }

// void    FragTrap::beRepaired(unsigned int amount)
// {
//     if (!_isAlive())
//         std::cout << "FragTrap " << this->_name << " is dead!" << std::endl;
//     else if (!_haveEnergy())
//         std::cout << "FragTrap " << this->_name << " is out of energy!" << std::endl;
//     else
//     {
//         this->_hitPoints += amount;
//         std::cout << "FragTrap " << this->_name << " repaired for " << amount << " hit points!" << std::endl;
//         this->_energyPoints--;
//     }
// }

void    FragTrap::highFiveGuys()
{
    std::cout << "FragTrap " << this->_name << "requests high fives!! Well aren't we all suckers for high fives!!" << std::endl;
}