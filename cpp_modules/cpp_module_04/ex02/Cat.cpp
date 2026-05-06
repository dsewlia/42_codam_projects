#include "Cat.hpp"

Cat::Cat()
{
    this->_brain = new Brain();
    this->_type = "Cat";
    std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat(std::string  type)
{
    if (this->_brain)
        delete (this->_brain);
    this->_brain = new Brain();
    this->_type = type;
    std::cout << "Cat: Constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat: Copy constructor" << std::endl;
}

Cat  &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        delete (this->_brain);
        this->_brain = new Brain(*rhs._brain);
    }
    std::cout << "Cat: Assignment operator overload" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    if (this->_brain)
        delete (this->_brain);
    std::cout << "Cat: Destructor" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << this->_type << ": Woof woof!!!!" << std::endl;
}

void    Cat::setIdea(int index, const std::string &idea)
{
    this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return (this->_brain->getIdea(index));
}
