#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: Wrong argument number." << std::endl;
        return 1;
    }
    BitcoinExchange bitcoin(av[1]);
    try {
        bitcoin.loadDatabase();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}