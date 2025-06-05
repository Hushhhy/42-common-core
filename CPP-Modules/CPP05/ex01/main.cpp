#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat b("JCVD", 150);
        Form a("letter", 150, 150);
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b.signForm(a);
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }

    try {
        Bureaucrat b("JCVD", 1);
        Form a("letter", 3, 2);
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b.signForm(a);
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }

    try {
        Bureaucrat b("JCVD", 50);
        Form a("letter", 30, 10);
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b.signForm(a);
    } catch (const Bureaucrat::GradeTooHighException &exception) {
        std::cerr << exception.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &exception) {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
}