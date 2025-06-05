#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &name, int signGrade, int executeGrade);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        std::string getName() const;
        std::string getTarget(Bureaucrat &bureaucrat) const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        bool isSigned() const;

        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too low!";
                }
        };
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &presidentialPardonForm);

#endif