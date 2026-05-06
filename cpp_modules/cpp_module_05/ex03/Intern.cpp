#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

Intern::~Intern()
{

}

AForm *Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    typedef AForm* (*FormCreator)(const std::string&);

    struct FormEntry {
        const char* name;
        FormCreator creator;
    };

	std::string fName = formName;
	for (size_t i = 0; i < fName.size(); ++i) {
    	fName[i] = std::tolower(static_cast<unsigned char>(fName[i]));
	}
	static const FormEntry formTable[3] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}
	};

    for (size_t i = 0; i < 3; ++i) {
        if (fName == formTable[i].name) {
            AForm* form = formTable[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    throw Intern::FormNotFoundException(formName);
}

Intern::FormNotFoundException::FormNotFoundException(
	const std::string &formName
	)
	: _exception_message("Cannot finf the form " + formName + " in the system") {

}

const char *Intern::FormNotFoundException::what() const throw()
{
	return _exception_message.c_str();
}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{

}