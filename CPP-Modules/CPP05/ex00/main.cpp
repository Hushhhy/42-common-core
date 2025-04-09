#include "Bureaucrat.hpp"

int main() {

    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Testing invalid grades:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    // Grade too high
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test for valid grades
    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test for invalid grades
    try {
        Bureaucrat b3("Charlie", 0);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Dave", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //PURE TESTING
    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Pure testing:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    try {
        Bureaucrat Alpha("Alpha", 1);
        Bureaucrat Beta("Beta", 150);
        Bureaucrat Charlie("Charlie", 75);
        std::cout << Alpha << std::endl;
        std::cout << Beta << std::endl;
        std::cout << Charlie << std::endl;
        Alpha.decrementGrade();
        Beta.incrementGrade();
        Charlie.incrementGrade();
        std::cout << Alpha << std::endl;
        std::cout << Beta << std::endl;
        std::cout << Charlie << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}