#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

#define CSV_NAME "./data.csv"

class BitcoinExchange {
    private:
    std::multimap<std::string, double> db;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange() {}

        const std::multimap<std::string, double>& getDb() const;
        static std::string trim(const std::string& s);
        static bool IsValidDate(std::string date);

        class CanNotOpenFileCSV : public std::exception {
            public:
            const char* what() const throw() {
                return "Error: Can't open CSV file";
            }
        };
        class InvalidCSV : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: Invalid CSV file";
                }
        };
};

#endif