#include "Form.hpp"

Form::Form() : _name(), _signGrade(), _executeGrade() {
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
}

Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
}

Form::~Form() {
}

std::string Form::getName() const {
    return this->_name;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecuteGrade() const {
    return this->_executeGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {

}