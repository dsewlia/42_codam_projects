#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor: Brain" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy Constructor: Brain" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &rhs)
{
    std::cout << "Assingment operator overload: Brain" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = rhs.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Default destructor: Brain" << std::endl;
}

void    Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}
