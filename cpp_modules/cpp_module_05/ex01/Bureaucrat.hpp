#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        /* Cononical defaults */
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat (const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        /* Getters */
        std::string getName() const;
        int         getGrade() const;

        /* Member functions */
        void        increamentGrade();
        void        decreamentGrade();
        void        signForm(Form &form);


        /* Custom Exception */
        class   GradeTooHighException : public std::exception
        {
            private:
                const std::string _exception_message;
            public:
                explicit GradeTooHighException(const std::string &bureaucratName);
				virtual ~GradeTooHighException() throw();
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                const std::string _exception_message;
            public:
                explicit GradeTooLowException(const std::string &bureaucratName);
				virtual ~GradeTooLowException() throw();
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif