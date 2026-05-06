#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain = nullptr;

    public:
    Cat();
    Cat(std::string type);
    Cat(const Cat &copy);
    Cat  &operator=(const Cat &rhs);
    ~Cat();

    void makeSound() const override;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif