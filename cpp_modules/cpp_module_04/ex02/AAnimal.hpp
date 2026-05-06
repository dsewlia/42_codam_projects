#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class   AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &copy);
        AAnimal  &operator=(const AAnimal &rhs);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string  getType() const;
};

#endif