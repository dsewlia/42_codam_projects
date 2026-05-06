#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

# define RRF_SIGN_GRADE 72
# define RRF_EXECUTE_GRADE 45
# define RRF_FORM_NAME "Robotomy Request Form"

class Bureaucrat;
class AForm;

static int check = 1;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &form);

#endif