#include "Zombie.hpp"

int Zombie::_count = 0;

Zombie::Zombie(void)
{

}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _index << " " << _name << " neutralised!!" << std::endl;
}

void    Zombie::setName(std::string name)
{
    _count++;
    this->_index = _count;
    this->_name = name;
}

void    Zombie::announce()
{
    std::cout << _index << " "<< _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
