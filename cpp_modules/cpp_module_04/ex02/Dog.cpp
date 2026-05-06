#include "Dog.hpp"

Dog::Dog()
{
    this->_brain = new Brain();
    this->_type = "Dog";
    std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog(std::string  type)
{
    if (this->_brain)
        delete (this->_brain);
    this->_brain = new Brain();
    this->_type = type;
    std::cout << "Dog: Constructor" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Dog: Copy constructor" << std::endl;
}

Dog  &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        delete (this->_brain);
        this->_brain = new Brain(*rhs._brain);
    }
    std::cout << "Dog: Assignment operator overload" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    if (this->_brain)
        delete (this->_brain);
    std::cout << "Dog: Destructor" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << this->_type << ": Woof woof!!!!" << std::endl;
}

void    Dog::setIdea(int index, const std::string &idea)
{
    this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return (this->_brain->getIdea(index));
}
