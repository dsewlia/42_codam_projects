#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "Unknow WrongAnimal";
    std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string  type)
{
    this->_type = type;
    std::cout << "WrongAnimal: Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "WrongAnimal: Copy constructor" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "WrongAnimal: Assignment operator overload" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << this->_type << ": AGRHHGRRRR!!!!" << std::endl;
}
