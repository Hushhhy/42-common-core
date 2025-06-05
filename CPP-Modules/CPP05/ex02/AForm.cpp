#include "AForm.hpp"

AForm::AForm() : _name(), _signGrade(), _executeGrade() {
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
}

AForm::~AForm() {
}

std::string AForm::getName() const {
    return this->_name;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecuteGrade() const {
    return this->_executeGrade;
}

bool AForm::isSigned() const {
    return this->_isSigned;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}


std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form \"" << form.getName() << "\", signed: " << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade();
    return os;
}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}