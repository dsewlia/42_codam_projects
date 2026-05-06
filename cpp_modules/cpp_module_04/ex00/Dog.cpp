#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog(std::string  type)
{
    this->_type = type;
    std::cout << "Dog: Constructor" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog: Copy constructor" << std::endl;
}

Dog  &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "Dog: Assignment operator overload" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << this->_type << ": Woof woof!!!!" << std::endl;
}
