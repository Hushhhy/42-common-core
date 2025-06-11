#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(0)); // Pour la robotomy

    Bureaucrat bob("Bob", 1);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    // Test ShrubberyCreationForm
    std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
    try {
        bob.executeForm(shrub); // Non signé
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    bob.signForm(shrub);
    bob.executeForm(shrub);
    low.executeForm(shrub); // Trop bas pour exécuter

    // Test RobotomyRequestForm
    std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
    bob.signForm(robo);
    for (int i = 0; i < 4; ++i)
        bob.executeForm(robo);

    // Test PresidentialPardonForm
    std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
    bob.signForm(pardon);
    bob.executeForm(pardon);

    // Test exceptions
    std::cout << "\n--- Exceptions ---" << std::endl;
    try {
        low.signForm(pardon); // Trop bas pour signer
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        low.executeForm(pardon); // Trop bas pour exécuter
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}