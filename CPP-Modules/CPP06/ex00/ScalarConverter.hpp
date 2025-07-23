#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &copy);
        ScalarConverter(const ScalarConverter &copy);
    public:
        static void convert(std::string literal);
};

#endif