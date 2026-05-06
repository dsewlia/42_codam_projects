#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
    {
        throw GradeTooHighException(this->getName());
    }
    else if (grade > 150)
    {
        throw GradeTooLowException(this->getName());
    }
    else
    {
        this->_grade = grade;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{

}

Bureaucrat   &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy) {
        this->_grade = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increamentGrade()
{
    if (this->_grade <= 1) {
        throw GradeTooHighException(this->getName());
    }
    else {
        this->_grade--;
    }
}

void Bureaucrat::decreamentGrade()
{
    if (this->_grade >= 150) {
        throw GradeTooLowException(this->getName());
    }
    else {
        this->_grade++;
    }
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
    stream << bureaucrat.getName() << ", Bureaucrat grade "<< bureaucrat.getGrade() << "." << std::endl;
    return (stream);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &bureaucratName)
    : _exception_message(bureaucratName + " grade is too high") {

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return _exception_message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &bureaucratName)
    : _exception_message(bureaucratName + " grade is too low") {

}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return _exception_message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	
}