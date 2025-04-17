#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
        Form(const std::string &name, int signGrade, int executeGrade);
        ~Form();
        
        const std::string &getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        friend std::ostream &operator<<(std::ostream &out, const Form &form);
};

#endif