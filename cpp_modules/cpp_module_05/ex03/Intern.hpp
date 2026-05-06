#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Intern
{
	private:
		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidential(const std::string& target);
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception
		{
			private:
				const std::string _exception_message;
			
				public:
					explicit FormNotFoundException(const std::string &formName);
					virtual ~FormNotFoundException() throw();
					virtual const char *what() const throw();
		};
};

#endif