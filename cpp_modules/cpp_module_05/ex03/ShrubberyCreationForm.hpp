#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"

# define SCF_SIGN_GRADE 145
# define SCF_EXECUTE_GRADE 137
# define SCF_FORM_NAME "Shrubbery Creation Form"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &form);

#endif