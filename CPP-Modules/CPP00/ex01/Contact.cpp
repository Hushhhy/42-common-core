#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

bool Contact::setContact() {
    do {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, firstName) || firstName.empty()) {
            if (std::cin.eof()) return false; // Stop if EOF is detected
            std::cout << "\033[1;31mFirst name cannot be empty.\033[0m" << std::endl;
            continue;
        }
        break;
    } while (true);

    do {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, lastName) || lastName.empty()) {
            if (std::cin.eof()) return false; // Stop if EOF is detected
            std::cout << "\033[1;31mLast name cannot be empty.\033[0m" << std::endl;
            continue;
        }
        break;
    } while (true);

    do {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, nickname) || nickname.empty()) {
            if (std::cin.eof()) return false; // Stop if EOF is detected
            std::cout << "\033[1;31mNickname cannot be empty.\033[0m" << std::endl;
            continue;
        }
        break;
    } while (true);

    do {
        std::cout << "Enter phone number (digits only): ";
        if (!std::getline(std::cin, phoneNumber) || phoneNumber.empty()) {
            if (std::cin.eof()) return false; // Stop if EOF is detected
            std::cout << "\033[1;31mPhone number cannot be empty.\033[0m" << std::endl;
            continue;
        }
        if (!isDigitsOnly(phoneNumber)) {
            std::cout << "\033[1;31mInvalid phone number. Please enter digits only.\033[0m" << std::endl;
            continue;
        }
        break;
    } while (true);

    do {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, darkestSecret) || darkestSecret.empty()) {
            if (std::cin.eof()) return false; // Stop if EOF is detected
            std::cout << "\033[1;31mDarkest secret cannot be empty.\033[0m" << std::endl;
            continue;
        }
        break;
    } while (true);

    return true;
}

bool Contact::isDigitsOnly(const std::string &str) const {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void Contact::displayContact() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::truncate(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displaySummary(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << truncate(firstName) << "|"
              << std::setw(10) << truncate(lastName) << "|"
              << std::setw(10) << truncate(nickname) << std::endl;
}
