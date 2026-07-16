#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& file_name) {
    this->file_name = file_name;
    const int nb_lines = isFileValid();
    if (nb_lines == 0)
        throw BitcoinExchange::InvalidFile();
    // TODO: add the data into the map
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return *this;
    this->file_name = other.file_name;
    this->db = other.db;
    return *this;
}

/*
* @brief check is a line is valid the line format must be YYYY-MM-DD|number
* @param the line
* @return true if the line is valid else false
*/
static bool isLineValid(std::string& line) {
    size_t i = 0;
    while (i < 4 && std::isdigit(line[i]))
        i++;
    if (i < 4 || line[i] != '-')
        return false;
    i++;
    while (i < 7 && std::isdigit(line[i]))
        i++;
    if (i < 7 && line[i] != '-')
        return false;
    i++;
    while (i < 10 && std::isdigit(line[i]))
        i++;
    if (i < 10 && line[i] != '|')
        return false;
}

size_t BitcoinExchange::isFileValid() {
    int res = 0;
    std::ifstream file(file_name, std::ios::in);
    if (!file.is_open()) {
        return 0;
    }
    std::string line;
    while (std::getline(file, line)) {
            if (!isLineValid(line)) {
                file.close();
                return 0;
            }
        res++;
    }
    file.close();
    return res;
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange btc) {

}