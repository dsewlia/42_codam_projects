#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SCF_FORM_NAME, SCF_SIGN_GRADE, SCF_EXECUTE_GRADE), _target("Unknown") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(SCF_FORM_NAME, SCF_SIGN_GRADE, SCF_EXECUTE_GRADE), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy.getTarget()) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned()) {
		throw NotSignedException(this->getName(), executor.getName());
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException("execute", this->getName(), executor.getName());
	}
	std::string file_name = this->getTarget() + "_shrubbery";
	std::ofstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    file.open(file_name.c_str());
	if (file.is_open()) {
		file << "       |\n";
		file << "      /|\\\n";
		file << "     //|\\\\\n";
		file << "    ///|\\\\\\\n";
		file << "   ////|\\\\\\\\\n";
		file << "  /////|\\\\\\\\\\\n";
		file << " //////|\\\\\\\\\\\\\n";
		file << "        ||\n";
		file << "        ||\n";
		file << "       ==== \n";
	}
}

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &form) {
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