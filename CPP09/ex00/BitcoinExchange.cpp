#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file_name) {
    this->file_name = file_name;

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return *this;
    file_name = other.file_name;
    db = other.db;
    return *this;
}

const std::multimap<std::string, double>& BitcoinExchange::getDb() const {
    return db;
}

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& btc) {
    
    return out;
}