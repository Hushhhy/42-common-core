#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: Usage: ./RPN <calcul>" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    try {
        int result = rpn.calculate();
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}