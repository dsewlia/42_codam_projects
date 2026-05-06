#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;

    public:
        /* Cononical defaults */
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        /* Getter */
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

		/* Pure Virtual Functions */
		virtual void		execute(Bureaucrat const &executor) const = 0;

        /* Member Function */
        void        beSigned(const Bureaucrat &bureaucrat);

        /* Custom Exceptions */
        class GradeTooHighException : public std::exception
        {
            private:
                const std::string _exception_message;
            public:
                explicit GradeTooHighException(const std::string &action, const std::string &formName, const std::string &bureaucratName = "");
				virtual ~GradeTooHighException() throw();
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                const std::string _exception_message;
            public:
                explicit GradeTooLowException(const std::string &action, const std::string &formName, const std::string &bureaucratName = "");
				virtual ~GradeTooLowException() throw();
                virtual const char *what() const throw();
        };

		class NotSignedException : public std::exception
		{
			private:
				const std::string _exception_message;
			public:
				explicit NotSignedException(const std::string &formName, const std::string &bureaucratName);
				virtual ~NotSignedException() throw();
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, AForm const &form);

#endif