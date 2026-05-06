#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->_type = "Unknow AAnimal";
    std::cout << "AAnimal: Default constructor" << std::endl;
}

AAnimal::AAnimal(std::string  type)
{
    this->_type = type;
    std::cout << "AAnimal: Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << "AAnimal: Copy constructor" << std::endl;
}

AAnimal  &AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "AAnimal: Assignment operator overload" << std::endl;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: Destructor" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->_type);
}

void    AAnimal::makeSound() const
{
    std::cout << this->_type << ": AGRHHGRRRR!!!!" << std::endl;
}
