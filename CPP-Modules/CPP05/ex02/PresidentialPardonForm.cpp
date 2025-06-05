#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name(), _signGrade(), _executeGrade() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, int signGrade, int executeGrade) 
    : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade > 25 || executeGrade > 5)
        throw GradeTooLowException();
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getName() const {
    return this->_name;
}

int PresidentialPardonForm::getSignGrade() const {
    return this->_signGrade;
}

int PresidentialPardonForm::getExecuteGrade() const {
    return this->_executeGrade;
}