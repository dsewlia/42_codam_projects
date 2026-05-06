#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain = nullptr;

    public:
    Dog();
    Dog(std::string type);
    Dog(const Dog &copy);
    Dog  &operator=(const Dog &rhs);
    ~Dog();

    void makeSound() const override;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif