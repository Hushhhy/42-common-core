#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <exception>

class BitcoinExchange {
    private:
        std::string _filename;
        std::map<std::string, double> _price;
    public:
        BitcoinExchange();
        BitcoinExchange(char* filename);
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &copy);
        ~BitcoinExchange();

        std::map<std::string, double> getPrice();

        void loadDatabase();
        void loadInput();

        void processInputFile(const std::string& filename);
        double getExchangeRate(const std::string& data);

        bool    isTxtCsvFile(const std::string& filename);
        bool    isValidDate(const std::string& date);
        bool    isLeapYear(long year);
        bool    isValidPrice(const std::string& price);
        int     fileFormat(std::string line);
};

#endif