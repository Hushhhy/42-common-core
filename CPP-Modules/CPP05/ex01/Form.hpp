#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form();
        Form(const std::string &name, int signGrade, int executeGrade);
        Form(const Form &copy);
        ~Form();

        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        

        Form &operator=(const Form &copy);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif