#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat: Default constructor" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(std::string  type)
{
    this->_type = type;
    std::cout << "Cat: Constructor" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
    std::cout << "Cat: Copy constructor" << std::endl;
}

Cat  &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "Cat: Assignment operator overload" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << this->_type << ": Meow!!!!" << std::endl;
}
