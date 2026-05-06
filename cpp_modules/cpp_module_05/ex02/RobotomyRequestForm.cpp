#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(RRF_FORM_NAME, RRF_SIGN_GRADE, RRF_EXECUTE_GRADE), _target("Unknown") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(RRF_FORM_NAME, RRF_SIGN_GRADE, RRF_EXECUTE_GRADE), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy.getTarget()) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned()) {
		throw NotSignedException(this->getName(), executor.getName());
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException("execute", this->getName(), executor.getName());
	}
	if (check % 2 == 1) {
		std::cout << this->getTarget() + " has been robotomized" << std::endl;
	}
	else {
		std::cout << this->getTarget() + " couldn't be robotomized. Try again" << std::endl;
	}
	check++;
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &form) {
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