#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class   Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal  &operator=(const Animal &rhs);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        std::string  getType() const;
};

#endif