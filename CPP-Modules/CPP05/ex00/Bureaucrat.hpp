#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
        
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif