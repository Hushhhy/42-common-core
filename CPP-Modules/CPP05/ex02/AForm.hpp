#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
        AForm(const std::string &name, int signGrade, int executeGrade);
        ~AForm();
        
        const std::string &getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat &bureaucrat);

        virtual void execute(const Bureaucrat &executor) const = 0;
        void checkExecutionRequirements(const Bureaucrat &executor) const;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };

        friend std::ostream &operator<<(std::ostream &out, const AForm &form);
};

#endif