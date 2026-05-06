#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

# define PPF_SIGN_GRADE 25
# define PPF_EXECUTE_GRADE 5
# define PPF_FORM_NAME "Presidential Pardon Form"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &form);

#endif