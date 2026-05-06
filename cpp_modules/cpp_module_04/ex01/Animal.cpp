#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "Unknow Animal";
    std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal(std::string  type)
{
    this->_type = type;
    std::cout << "Animal: Constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal: Copy constructor" << std::endl;
}

Animal  &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "Animal: Assignment operator overload" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}

void    Animal::makeSound() const
{
    std::cout << this->_type << ": AGRHHGRRRR!!!!" << std::endl;
}
