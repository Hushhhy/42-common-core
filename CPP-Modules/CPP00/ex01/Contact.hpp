#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        std::string truncate(const std::string &str) const;
        bool isDigitsOnly(const std::string &str) const;

    public:
        Contact();
        ~Contact();
        bool setContact();
        void displayContact() const;
        void displaySummary(int index) const;
};

#endif