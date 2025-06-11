#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm("ShrubberyCreationForm", 145, 137), _target(copy._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: could not create file." << std::endl;
        return;
    }
    file << "   ^\n"
            "  ^^^\n"
            " ^^^^^\n"
            "^^^^^^^\n"
            "  |||  \n";
    file.close();
}