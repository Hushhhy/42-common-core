#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        Form formA("FormA", 50, 100);
        Form formB("FormB", 1, 1);
        Form formC("FormC", 151, 1); // This will throw an exception

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        alice.signForm(formA); // Should succeed
        bob.signForm(formA);   // Should fail

        alice.signForm(formB); // Should succeed
        bob.signForm(formB);   // Should fail

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}