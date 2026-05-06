#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown"), _grade_to_sign(150), _grade_to_execute(150)
{
    _signed = false;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _grade_to_sign(gradeToSign), _grade_to_execute(gradeToExecute)
{
	if (gradeToExecute > 150 || gradeToSign > 150) {
		throw GradeTooLowException("create", name);
	} else if (gradeToExecute < 1 || gradeToSign < 1) {
		throw GradeTooHighException("create", name);
	}
    _signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
    _signed = copy._signed;
}

Form &Form::operator=(const Form &copy)
{
    _signed = copy._signed;
    return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getIsSigned() const
{
    return (this->_signed);
}

int Form::getGradeToSign() const
{
    return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const
{
    return (this->_grade_to_execute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_to_sign) {
        this->_signed = true;
    }
    else {
        throw GradeTooLowException("sign", this->getName(), bureaucrat.getName());
    }
}

Form::GradeTooHighException::GradeTooHighException(
    const std::string &action,
    const std::string &formName,
	const std::string &bureaucratName
    )
    :  _exception_message(bureaucratName + (bureaucratName.empty() ? "" : " ") + "cannot " + action + " " + formName + " because grade is too high\n"){
}

const char *Form::GradeTooHighException::what() const throw()
{
    return _exception_message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(
    const std::string &action,
    const std::string &formName,
	const std::string &bureaucratName
    )
    :  _exception_message(bureaucratName + (bureaucratName.empty() ? "" : " ") + "cannot " + action + " " + formName + " because grade is too low\n"){
}

const char *Form::GradeTooLowException::what() const throw()
{
    return _exception_message.c_str();
}

std::ostream &operator<<(std::ostream &stream, Form const &form)
{
    std::ios_base::fmtflags oldFlags = stream.flags();
    stream  << "Form Name: " << form.getName() 
            << ". Is signed: " << std::boolalpha << form.getIsSigned() 
            << ". Grade to sign: " << form.getGradeToSign() 
            << ". Grade to execute: " << form.getGradeToExecute() 
            << "." << std::endl;
    stream.flags(oldFlags);
    return (stream);
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{

}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	
}