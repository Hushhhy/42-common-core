#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::string form1 = "robotomy request";
    std::string form2 = "presidential pardon";
    std::string form3 = "Shrubbery creation";
    std::string form4 = "unknown form";

    AForm* rrf = someRandomIntern.makeForm(form1, std::string("Bender"));
    AForm* ppf = someRandomIntern.makeForm(form2, std::string("Arthur Dent"));
    AForm* scf = someRandomIntern.makeForm(form3, std::string("garden"));
    AForm* fail = someRandomIntern.makeForm(form4, std::string("nobody"));

    std::cout << "\n--- Signature et exécution ---" << std::endl;
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }
    if (fail)
        delete fail;

    return 0;
}