#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "The memory address of the string variable: " << &brain << "\n";
    std::cout << "The memory address held by stringPTR: " << &stringPTR << "\n";
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "The value of the string variable: " << brain << "\n";
    std::cout << "The value pointed to by stringPTR: " << stringPTR << "\n";
    std::cout << "The dereference value of stringPTR: " << *stringPTR << "\n";
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    return (0);
}
