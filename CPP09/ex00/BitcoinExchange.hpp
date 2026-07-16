#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <ostream>
#include <string>

class BitcoinExchange {
    private:
        std::string file_name;
        std::multimap<std::string, double> db;

        BitcoinExchange();
    public:
        static const char* csv;

        BitcoinExchange(const std::string& file_name);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange() {}

        const std::multimap<std::string, double>& getDb() const;

        class CanNotOpenFile : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: Can't open the file provide";
                }
        };
        class InvalidFile : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: The data base inside the file is invalid";
                }
        };
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

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& btc);

#endif