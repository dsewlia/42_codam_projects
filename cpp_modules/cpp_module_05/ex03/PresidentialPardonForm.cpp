#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(PPF_FORM_NAME, PPF_SIGN_GRADE, PPF_EXECUTE_GRADE), _target("Unknown") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PPF_FORM_NAME, PPF_SIGN_GRADE, PPF_EXECUTE_GRADE), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy.getTarget()) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned()) {
		throw NotSignedException(this->getName(), executor.getName());
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException("execute", this->getName(), executor.getName());
	}
	std::cout << this->getTarget() + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &form) {
	std::ios_base::fmtflags oldFlags = stream.flags();
    stream  << "Form Name: " << form.getName() 
			<< ". Grade to sign: " << form.getGradeToSign() 
            << ". Is signed: " << std::boolalpha << form.getIsSigned()
			<< ". Grade to execute: " << form.getGradeToExecute() 
			<< ". Target: " << form.getTarget()
            << "." << std::endl;
    stream.flags(oldFlags);
    return (stream);
}