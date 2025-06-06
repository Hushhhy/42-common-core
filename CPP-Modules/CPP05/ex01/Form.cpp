#include "Form.hpp"

Form::Form() : _name(), _signGrade(), _executeGrade() {
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
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

bool Form::isSigned() const {
    return this->_isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form \"" << form.getName() << "\", signed: " << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade();
    return os;
}

Form &Form::operator=(const Form &copy) {
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}