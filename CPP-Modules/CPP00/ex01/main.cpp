#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "\033[1;34mWelcome to the 80s - Crappy Awesome PhoneBook!\033[0m" << std::endl;
    std::cout << "Commands: \033[1;32mADD\033[0m, \033[1;33mSEARCH\033[0m, \033[1;31mEXIT\033[0m" << std::endl;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\033[1;31mExiting... Goodbye!\033[0m" << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "\033[1;31mExiting... Goodbye!\033[0m" << std::endl;
            break;
        } else if (!command.empty()) {
            std::cout << "\033[1;31mInvalid command. Try ADD, SEARCH, or EXIT.\033[0m" << std::endl;
        }
    }

    return 0;
}
