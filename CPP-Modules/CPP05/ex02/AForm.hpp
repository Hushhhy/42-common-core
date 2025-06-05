#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &copy);
        ~AForm();

        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        bool isSigned() const;

        void execute(Bureaucrat const & executor) const;

        AForm &operator=(const AForm &copy);

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

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif