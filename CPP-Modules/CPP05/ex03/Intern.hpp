#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    public:
        AForm *makeForm(const std::string &form, const std::string &target);
};

#endif