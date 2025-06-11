#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm("RobotomyRequestForm", 72, 45), _target(copy._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        AForm::operator=(copy);
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "DRRRRRRrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized succesfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}