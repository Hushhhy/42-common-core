#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
        if (signGrade < 1 || executeGrade < 1)
            throw GradeTooHighException();
        if (signGrade > 150 || executeGrade > 150)
            throw GradeTooLowException();
}

AForm::~AForm() {
}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecuteGrade() const {
    return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << " ["
        << (form.getIsSigned() ? "Signed" : "Not Signed")
        << "], Sign Grade: " << form.getSignGrade()
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}

void AForm::checkExecutionRequirements(const Bureaucrat &executor) const {
    if (!isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw AForm::GradeTooLowException();
}