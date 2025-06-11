#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*FormCreator)(const std::string &target);

static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &form, const std::string &target) {
    struct FormPair {
        const char* name;
        FormCreator creator;
    } forms[] = {
        {"Shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };
    for (size_t i = 0; i < 3; ++i) {
        if (form == forms[i].name) {
            std::cout << "Intern creates " << form << std::endl;
            return forms[i].creator(target);
        }
    }
    std::cout << "Error: Form name \"" << form << "\" does not exist." << std::endl;
    return NULL;
}
