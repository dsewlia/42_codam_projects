#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat: Default constructor" << std::endl;
}

WrongCat::WrongCat(std::string  type)
{
    this->_type = type;
    std::cout << "WrongCat: Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "WrongCat: Copy constructor" << std::endl;
}

WrongCat  &WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << "WrongCat: Assignment operator overload" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << this->_type << ": Meow!!!!" << std::endl;
}
