#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
        if (signGrade < 1 || executeGrade < 1)
            throw GradeTooHighException();
        if (signGrade > 150 || executeGrade > 150)
            throw GradeTooLowException();
}

Form::~Form() {
}

const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecuteGrade() const {
    return executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " ["
        << (form.getIsSigned() ? "Signed" : "Not Signed")
        << "], Sign Grade: " << form.getSignGrade()
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}