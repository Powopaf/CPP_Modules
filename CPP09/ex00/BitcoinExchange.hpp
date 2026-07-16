#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstddef>
#include <map>
#include <ostream>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> db;
        std::string file_name;
        BitcoinExchange();
    public:
        BitcoinExchange(const std::string& file_name);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange() {}

        size_t isFileValid();

        class InvalidFile {
            public:
                const char* what() const throw() {
                    return "The Data base provide is not valid";
                }
        };
};

std::ostream& operator<<(std::ostream& out, BitcoinExchange& btc);

#endif