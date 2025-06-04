#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat b("JCVD", 150);
        std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
        b.decrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }

    try {
        Bureaucrat c("Ali Baba", 0);
        std::cout << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }

    try {
        Bureaucrat d("Jackie Chan", 151);
        std::cout << d.getName() << ", bureaucrat grade " << d.getGrade() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
}