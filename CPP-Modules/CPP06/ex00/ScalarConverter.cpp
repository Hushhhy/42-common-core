#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}

void ScalarConverter::convert(std::string literal) {
    // PSEUDO LITERAUX DOUBLE && FLOAT
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return ;
    } else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return ;
    }
    //CHAR
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        if (std::isprint(c))
            std::cout << "char: '" << literal << "'" << std::endl;
        else 
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" <<std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return ;
    }
    //INT
    char *end = NULL;
    errno = 0;
    long i = strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && errno != ERANGE && i >= INT_MIN && i <= INT_MAX) {
        int val = static_cast<int>(i);
        if (val >= 0 && val <= 127) {
            if (std::isprint(val))
                std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << val << std::endl;
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
        return ;   
    }
    //FLOAT
    if (literal.find('f') == literal.length() - 1 && literal.length() > 1) {
        errno = 0;
        char *end = NULL;
        float f = std::strtof(literal.c_str(), &end);
        if (errno != ERANGE && end != literal.c_str() && *end == 'f' && *(end + 1) == '\0') {
            if (f >= 32 && f <= 126 && f == static_cast<int>(f))
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
            else if (f >= 0 && f <= 127 && f == static_cast<int>(f))
                std::cout << "char: Non displayable" << std::endl;
            else 
                std::cout << "char: impossible" << std::endl;
            if (f >= static_cast<float>(std::numeric_limits<int>::min()) &&
                f <= static_cast<float>(std::numeric_limits<int>::max()) &&
                f == static_cast<int>(f))
                std::cout << "int: " << static_cast<int>(f) << std::endl;
            else
                std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << f;
            if (f == static_cast<int>(f))
                std::cout << ".0f" << std::endl;
            else
                std::cout << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f);
            if (f == static_cast<int>(f))
                std::cout << ".0" << std::endl;
            else
                std::cout << std::endl;
            return ;
        }
    }
    //DOUBLE
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);
    if (*end == '\0' && errno != ERANGE) {
        if (d >= 32 && d <= 126 && d == static_cast<int>(d))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else if (d >= 0 && d <= 127 && d == static_cast<int>(d))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d >= static_cast<double>(std::numeric_limits<int>::min()) &&
            d <= static_cast<double>(std::numeric_limits<int>::max()) &&
            d == static_cast<int>(d))
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        float f = static_cast<float>(d);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
        return ;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}