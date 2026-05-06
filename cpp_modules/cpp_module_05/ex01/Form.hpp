#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;

    public:
        /* Cononical defaults */
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        /* Getter */
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

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
};

std::ostream &operator<<(std::ostream &stream, Form const &form);

#endif