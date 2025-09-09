#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _filename(copy._filename), _price(copy._price) {}

BitcoinExchange::BitcoinExchange(char* filename) : _filename(std::string(filename)) {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
    if (this != &copy) {
        this->_filename = copy._filename;
        this->_price = copy._price;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::getPrice() {
    return this->_price;
}

void BitcoinExchange::loadDatabase() {
    std::ifstream dataBase("data.csv");
    if (!dataBase || !dataBase.is_open() || dataBase.bad())
        throw std::runtime_error("Error: could not open database.");
    std::string line;
    std::getline(dataBase, line);
    while (std::getline(dataBase, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rate = line.substr(commaPos + 1);
            this->_price[date] = std::strtod(rate.c_str(), NULL);
        }
    }
    dataBase.close();
    loadInput();
}

void BitcoinExchange::loadInput() {
    const std::string filename(this->_filename);
    if (!isTxtCsvFile(filename))
        throw std::runtime_error("Error: not a .csv or .txt file.");
    std::ifstream file(this->_filename.c_str());
    if (!file || !file.is_open()|| file.bad())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos);
        std::string price = line.substr(pipePos + 1);
        while (!date.empty() && isspace(date[date.length() - 1])) {
            date.erase(date.length() - 1);
        }
        while (!price.empty() && isspace(price[0])) {
            price.erase(0, 1);
        }
        while (!price.empty() && isspace(price[price.length() - 1])) {
            price.erase(price.length() - 1);
        }
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        try {
            if (isValidPrice(price)) {
                double value = std::strtod(price.c_str(), NULL); 
                double rate = getExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) {
    std::map<std::string, double>::iterator it = this->_price.lower_bound(date);
    if (it != this->_price.begin() && it->first != date) {
        --it;
    }
    if (it == this->_price.end()) {
        throw std::runtime_error("Error: no exchange rate available for this date.");
    }
    return it->second;
}


bool BitcoinExchange::isTxtCsvFile(const std::string& filename) {
    if (filename.length() < 4)
        return false;
    std::string extension = filename.substr(filename.length() - 4);
    return (extension == ".csv" || extension == ".txt");
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }
    std::string str_year = date.substr(0, 4);
    long year = std::strtol(str_year.c_str(), NULL, 10);
    std::string str_month = date.substr(5, 2);
    long month = std::strtol(str_month.c_str(), NULL, 10);
    if (month < 1 || month > 12)
        return false;
    std::string str_day = date.substr(8, 2);
    long day = std::strtol(str_day.c_str(), NULL, 10);
    if (day < 1)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day > daysInMonth[month - 1])
        return false;
    time_t now = time(0);
    tm *local = localtime(&now);
    if (year > 1900 + local->tm_year)
        return false;
    if (year == 1900 + local->tm_year && month > 1 + local->tm_mon)
        return false;
    if (year == 1900 + local->tm_year && month == local->tm_mon + 1 && day > local->tm_mday)
        return false;
    return true;
}

bool BitcoinExchange::isLeapYear(long year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool isDigit(const std::string& price) {
    for (int i = 0; price[i]; i++) {
        if (!isdigit(price[i]) && price[i] != '.' && price[i] != '-')
            return false;
    } return true;
}

bool BitcoinExchange::isValidPrice(const std::string& price) {
    if (std::count(price.begin(), price.end(), '.') > 1 || !isDigit(price))
        throw std::runtime_error("Error: not a number.");
    float fprice = std::strtof(price.c_str(), NULL);
    if (fprice < 0)
        throw std::runtime_error("Error: not a positive number.");
    else if (fprice > 1000)
        throw std::runtime_error("Error: too large a number.");
    return true;
}