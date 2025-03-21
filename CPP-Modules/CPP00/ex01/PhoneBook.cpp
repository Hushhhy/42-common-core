#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    if (contactCount < 8) {
        if (!contacts[contactCount].setContact())
            return; // Stop if EOF is detected
        contactCount++;
    } else {
        if (!contacts[oldestContactIndex].setContact())
            return; // Stop if EOF is detected
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    std::cout << "\033[1;32mContact added successfully!\033[0m" << std::endl;
}

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "\033[1;31mNo contacts available.\033[0m" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; i++) {
        contacts[i].displaySummary(i);
    }

    int index;
    while (true) {
        std::cout << "Enter the index of the contact to display: ";
        std::cin >> index;
        if (std::cin.eof()) {
            std::cout << "\033[1;31mExiting search...\033[0m" << std::endl;
            std::cin.clear();
            return;
        }
        if (std::cin.fail() || index < 0 || index >= contactCount) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid index. Please try again.\033[0m" << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            contacts[index].displayContact();
            break;
        }
    }
}
