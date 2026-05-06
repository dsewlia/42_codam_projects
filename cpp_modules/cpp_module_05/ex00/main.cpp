#include "Bureaucrat.hpp"
#include <sstream>
#include <limits>

std::string getName()
{
    std::string name;
    std::getline(std::cin, name);
    return name;
}

int getInteger()
{
    std::string line;
    int grade;
    while (true) {
        std::getline(std::cin,line);
        std::istringstream iss(line);
        if (!(iss >> grade) || !(iss.eof())) {
            std::cout << "Invalid input. PLease enter an integer" << std::endl;
            continue;
        }
        return grade;
    }
}

int main()
{
    Bureaucrat* b1 = NULL;
    bool created = false;

    while (1)
    {
        std::cout << "1: Create Bureaucrat\n"
                  << "2: Increment grade\n"
                  << "3: Decrement grade\n"
                  << "4: Exit\n" << std::endl;

        int test = getInteger();

        if (test < 1 || test > 4) {
            std::cout << "Enter a valid input\n";
            continue;
        }

        if (!created && test != 1 && test != 4) {
            std::cout << "Create a Bureaucrat first\n";
            continue;
        }

        try {
            switch (test)
            {
                case 1:
                {
                    std::cout << "Enter the name" << std::endl;
                    std::string name = getName();
                    std::cout << "Enter the Grade" << std::endl;
                    int grade = getInteger();
                    if (b1 != NULL) {
                        std::cout << "Deleting the below Bureaucrat" << std::endl;
                        std::cout << *b1 << std::endl;
                        delete b1;
                        b1 = NULL;
                    }
                    b1 = new Bureaucrat(name, grade);
                    created = true;
                    std::cout << *b1 << std::endl;
                    break;
                }

                case 2:
                    b1->increamentGrade();
                    std::cout << *b1 << std::endl;
                    break;

                case 3:
                    b1->decreamentGrade();
                    std::cout << *b1 << std::endl;
                    break;

                case 4:
                    if (b1 != NULL) {
                        delete b1;
                        b1 = NULL;
                    }
                    return 0;
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}