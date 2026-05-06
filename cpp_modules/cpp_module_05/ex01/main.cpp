#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <limits>
#include <sstream>

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
    Form *f1 = NULL;
    bool createdBureaucrat = false;
    bool createdForm = false;

    while (1)
    {
        std::cout << "\n1: Create Bureaucrat\n"
                  << "2: Increment grade\n"
                  << "3: Decrement grade\n"
                  << "4: Create Form\n"
                  << "5: Sign Form\n"
                  << "6: Be Signed\n"
                  << "7: Exit\n" << std::endl;

        int test = getInteger();

        if (test < 1 || test > 7) {
            std::cout << "Enter a valid input\n";
            continue;
        }

        try {
            switch (test)
            {
                case 1:
                {
                    std::cout << "Enter the Buraucrat name" << std::endl;
                    std::string name = getName();
                    std::cout << "Enter the Bureaucrat grade" << std::endl;
                    int grade = getInteger();
                    if (b1 != NULL) {
                        std::cout << "Deleting the below Bureaucrat" << std::endl;
                        std::cout << *b1 << std::endl;
                        delete b1;
                        b1 = NULL;
                    }
                    b1 = new Bureaucrat(name, grade);
                    createdBureaucrat = true;
                    std::cout << "Bureaucrat created successfully" << std::endl;
                    std::cout << *b1 << std::endl;
                    break;
                }

                case 2:
                    if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
                    }
                    b1->increamentGrade();
                    std::cout << *b1 << std::endl;
                    break;

                case 3:
                    if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
                    }
                    b1->decreamentGrade();
                    std::cout << *b1 << std::endl;
                    break;
                
                case 4:
                {
                    std::cout << "Enter the form name" << std::endl;
                    std::string formName = getName();
                    std::cout << "Enter the grade required to sign it" << std::endl;
                    int signGrade = getInteger();
                    std::cout << "Enter the grade required to execute it" << std::endl;
                    int executeGrade = getInteger();
                    if (f1 != NULL) {
                        std::cout << "Deleting the below Form" << std::endl;
                        std::cout << *f1 << std::endl;
                        f1 = NULL;
                    }
                    f1 = new Form(formName, signGrade, executeGrade);
                    createdForm = true;
                    std::cout << "Form created successfully" << std::endl;
                    std::cout << *f1 << std::endl;
                    break;
                }

                case 5:
                    if (!f1 && !b1) {
                        throw std::string("Please create a Bureaucrat and a form first");
                    }
                    if (!f1) {
                        throw std::string("Please create a Form first");
                    }
                    if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
                    }
                    b1->signForm(*f1);
                    break;

                case 6:
                    if (!f1 && !b1) {
                        throw std::string("Please create a Bureaucrat and a form first");
                    }
                    if (!f1) {
                        throw std::string("Please create a Form first");
                    }
                    if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
                    }
                    f1->beSigned(*b1);
                    break;

                case 7:
                    if (b1 != NULL) {
                        delete b1;
                        b1 = NULL;
                    }
                    return 0;
                    break;
            }
        }
        catch (std::string &errorMessage)
        {
            std::cerr << errorMessage << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        if (b1) {
            std::cout << "\nCurrent status of Bureaucrat:\n" << *b1 << std::endl;
        } else {
            std::cout << "\nNo Bureaucrat found" << std::endl;
        }
        if (f1) {
            std::cout << "Current status of form:\n" << *f1 << std::endl;
        } else {
            std::cout << "No form found" << std::endl;
        }
    }
    return 0;
}