#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <limits>
#include <sstream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    ShrubberyCreationForm *scf = NULL;
	RobotomyRequestForm *rrf = NULL;
	PresidentialPardonForm *ppf = NULL;

    while (1)
    {
        std::cout << "\n1:  Create Bureaucrat\n"
                  << "2:  Increment grade\n"
                  << "3:  Decrement grade\n"
                  << "4:  Create Shrubbery Creation Form\n"
				  << "5:  Sign Form -  Shrubbery Creation Form\n"
				  << "6:  Be Signed - Shrubbery Creation Form\n"
				  << "7:  Execute - Shrubbery Creation Form\n"
				  << "8:  ExecuteForm - Shrubbery Creation Form\n"
				  << "9:  Create Robotomy Request Form\n"
				  << "10: Sign Form -  Robotomy Request Form\n"
				  << "11: Be Signed - Robotomy Request Form\n"
				  << "12: Execute - Robotomy Request Form\n"
				  << "13: ExecuteForm - Robotomy Request Form\n"
				  << "14: Create Presidential Pardon Form\n"
				  << "15: Sign Form -  Presidential Pardon Form\n"
				  << "16: Be Signed - Presidential Pardon Form\n"
				  << "17: Execute - Presidential Pardon Form\n"
				  << "18: ExecuteForm - Presidential Pardon Form\n"
                  << "19: Exit\n" << std::endl;

        int test = getInteger();

        if (test < 1 || test > 19) {
            throw std::string("Enter a valid input");
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
					if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
						continue;
                    }
					std::cout << "Creating Shrubbery Creation Form" << std::endl;
                    std::cout << "Enter the target" << std::endl;
                    std::string targetName = getName();
                    if (scf != NULL) {
                        std::cout << "Deleting the below Form" << std::endl;
                        std::cout << *scf << std::endl;
                        delete scf;
						scf = NULL;
                    }
                    scf = new ShrubberyCreationForm(targetName);
                    std::cout << "Form created successfully" << std::endl;
                    std::cout << *scf << std::endl;
                    break;
                }

				case 5:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!scf) {
						throw std::string("Please create the Shrubbery Creation Form");
					}
					b1->signForm(*scf);
					break;
				}

				case 6:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!scf) {
						throw std::string("Please create the Shrubbery Creation Form");
					}
					scf->beSigned(*b1);
					break;
				}

				case 7:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!scf) {
						throw std::string("Please create the Shrubbery Creation Form");
					}
					scf->execute(*b1);
					break;
				}

				case 8:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!scf) {
						throw std::string("Please create the Shrubbery Creation Form");
					}
					b1->executeForm(*scf);
					break;
				}

				case 9:
                {
					if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
						continue;
                    }
					std::cout << "Creating Robotomy Request Form" << std::endl;
                    std::cout << "Enter the target" << std::endl;
                    std::string targetName = getName();
                    if (rrf != NULL) {
                        std::cout << "Deleting the below Form" << std::endl;
                        std::cout << *rrf << std::endl;
                        delete rrf;
						rrf = NULL;
                    }
                    rrf = new RobotomyRequestForm(targetName);
                    std::cout << "Form created successfully" << std::endl;
                    std::cout << *rrf << std::endl;
                    break;
                }

				case 10:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!rrf) {
						throw std::string("Please create the Robotomy Request Form");
					}
					b1->signForm(*rrf);
					break;
				}

				case 11:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!rrf) {
						throw std::string("Please create the Robotomy Request Form");
					}
					rrf->beSigned(*b1);
					break;
				}

				case 12:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!rrf) {
						throw std::string("Please create the Robotomy Request Form");
					}
					rrf->execute(*b1);
					break;
				}

				case 13:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!rrf) {
						throw std::string("Please create the Robotomy Request Form");
					}
					b1->executeForm(*rrf);
					break;
				}

				case 14:
                {
					if (!b1) {
                        throw std::string("Please create a Bureaucrat first");
						continue;
                    }
					std::cout << "Creating Presidential Pardon Form" << std::endl;
                    std::cout << "Enter the target" << std::endl;
                    std::string targetName = getName();
                    if (ppf != NULL) {
                        std::cout << "Deleting the below Form" << std::endl;
                        std::cout << *ppf << std::endl;
                        delete ppf;
						ppf = NULL;
                    }
                    ppf = new PresidentialPardonForm(targetName);
                    std::cout << "Form created successfully" << std::endl;
                    std::cout << *ppf << std::endl;
                    break;
                }

				case 15:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!ppf) {
						throw std::string("Please create the Presidential Pardon Form");
					}
					b1->signForm(*ppf);
					break;
				}

				case 16:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!ppf) {
						throw std::string("Please create the Presidential Pardon Form");
					}
					ppf->beSigned(*b1);
					break;
				}

				case 17:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!ppf) {
						throw std::string("Please create the Presidential Pardon Form");
					}
					ppf->execute(*b1);
					break;
				}

				case 18:
				{
					if (!b1) {
						throw std::string("Please create a Bureaucrat");
					}
					if (!ppf) {
						throw std::string("Please create the Presidential Pardon Form");
					}
					b1->executeForm(*ppf);
					break;
				}

				case 19:
					if (b1) {
						delete b1;
						b1 = NULL;
					}
					if (scf) {
						delete scf;
						scf = NULL;
					}
					if (rrf) {
						delete rrf;
						rrf = NULL;
					}
					if (ppf) {
						delete (ppf);
						ppf = NULL;
					}
					std::cout << "Good bye!" << std::endl;
					return 0;
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
        if (scf || rrf || ppf) {
            std::cout << "Current status of forms:" << std::endl;
			if (scf)
				std::cout << *scf << std::endl;
			if (rrf)
				std::cout << *rrf << std::endl;
			if (ppf)
				std::cout << *ppf << std::endl;
        } else {
            std::cout << "No forms found" << std::endl;
        }
    }
    return 0;
}