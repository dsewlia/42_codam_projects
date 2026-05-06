#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "J is of type: " << j->getType() << std::endl;
    std::cout << "I is of type: " << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongI = new WrongCat();

    std::cout << "wrongI is of type: " << wrongI->getType() << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongI;

    return (0);
}
