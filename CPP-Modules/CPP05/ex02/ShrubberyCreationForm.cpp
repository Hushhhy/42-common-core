#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecutionRequirements(executor);
    
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: Cannot open file.\n";
        return;
    }

    file << "       ccee88oo\n"
         << "  C8O8O8Q8PoOb o8oo\n"
         << " dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "    6OuU  /p u gcoUodpP\n"
         << "      \\\\//  /douUP\n"
         << "        \\\\////\n"
         << "         |||/\\\n"
         << "         |||\\/\n"
         << "         |||||\n"
         << "   .....//||||\\....\n";

    file.close();
}