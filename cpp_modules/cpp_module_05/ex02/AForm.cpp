#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _grade_to_sign(150), _grade_to_execute(150)
{
    _signed = false;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _grade_to_sign(gradeToSign), _grade_to_execute(gradeToExecute)
{
	if (gradeToExecute > 150 || gradeToSign > 150) {
		throw GradeTooLowException("create", name);
	} else if (gradeToExecute < 1 || gradeToSign < 1) {
		throw GradeTooHighException("create", name);
	}
    _signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
    _signed = copy._signed;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy) {
		_signed = copy._signed;
	}
    return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getIsSigned() const
{
    return (this->_signed);
}



int AForm::getGradeToSign() const
{
    return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
    return (this->_grade_to_execute);
}



void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_to_sign) {
        this->_signed = true;
    }
    else {
        throw GradeTooLowException("sign", this->getName(), bureaucrat.getName());
    }
}

AForm::GradeTooHighException::GradeTooHighException(
    const std::string &action,
    const std::string &formName,
	const std::string &bureaucratName
    )
    :  _exception_message(bureaucratName + (bureaucratName.empty() ? "" : " ") + "cannot " + action + " " + formName + " because grade is too high\n"){
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return _exception_message.c_str();
}

AForm::NotSignedException::NotSignedException(
	const std::string &formName,
	const std::string &bureaucratName
	)
	: _exception_message(bureaucratName + " cannot execute the form " + formName + " because it is not signed yet\n") {
}

const char *AForm::NotSignedException::what() const throw()
{
	return _exception_message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(
    const std::string &action,
    const std::string &formName,
	const std::string &bureaucratName
    )
    :  _exception_message(bureaucratName + (bureaucratName.empty() ? "" : " ") + "cannot " + action + " " + formName + " because grade is too low\n"){
}


const char *AForm::GradeTooLowException::what() const throw()
{
    return _exception_message.c_str();
}

std::ostream &operator<<(std::ostream &stream, AForm const &form)
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

AForm::GradeTooHighException::~GradeTooHighException() throw()
{

}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	
}

AForm::NotSignedException::~NotSignedException() throw()
{
	
}