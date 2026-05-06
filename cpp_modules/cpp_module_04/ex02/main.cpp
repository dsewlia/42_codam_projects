#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"

int main()
{
    int size = 4;
    AAnimal *animals[size];
	// AAnimal a;

    for (int i = 0; i < size; i++)
    {
        if (i < size/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    Dog originalDog;
    originalDog.setIdea(0, "Let's chase a cat!");
    Dog copiedDog(originalDog);
    std::cout << "original dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copied dog idea: " << copiedDog.getIdea(0) << std::endl;
    originalDog.setIdea(0, "Eat shoes!");
    std::cout << "Testing deep copy, changed original dog idea(0)" << std::endl;
    std::cout << "original dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copied dog idea: " << copiedDog.getIdea(0) << std::endl;
    for (int i = 0; i < size; i++)
        delete (animals[i]);
    return (0);
}
