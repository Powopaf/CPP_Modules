#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <utility>

static bool IsValidLine(std::string line) {
    line = BitcoinExchange::trim(line);
    if (line.empty())
        return false;
    size_t comma = line.find(',');
    if (comma == std::string::npos)
        return false;
    std::string date = BitcoinExchange::trim(line.substr(0, comma));
    std::string val = BitcoinExchange::trim(line.substr(comma + 1));
    if (!BitcoinExchange::IsValidDate(date))
        return false;
    if (val.empty())
        return false;
    {
        char *endptr = NULL;
        std::strtod(val.c_str(), &endptr);
        if (endptr == val.c_str())
            return false;
    }
    return true;
}

BitcoinExchange::BitcoinExchange() {
    std::ifstream file(CSV_NAME, std::ios::in);
    if (!file.is_open())
        throw BitcoinExchange::CanNotOpenFileCSV();
    std::string line;
    if (!std::getline(file, line))
        throw BitcoinExchange::InvalidCSV();
    std::string header = BitcoinExchange::trim(line);
    if (header != "date,exchange_rate")
        throw BitcoinExchange::InvalidCSV();
    while (std::getline(file, line)) {
        if (BitcoinExchange::trim(line).empty())
            continue;
        if (!IsValidLine(line))
            throw BitcoinExchange::InvalidCSV();
        size_t comma_idx = line.find(',');
        std::string key = BitcoinExchange::trim(line.substr(0, comma_idx));
        std::string num_str = BitcoinExchange::trim(line.substr(comma_idx + 1));
        char *endptr = NULL;
        double num = std::strtod(num_str.c_str(), &endptr);
        if (endptr == num_str.c_str())
            throw BitcoinExchange::InvalidCSV();
        db.insert(std::make_pair(key, num));
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return *this;
    db = other.db;
    return *this;
}

const std::multimap<std::string, double>& BitcoinExchange::getDb() const {
    return db;
}

std::string BitcoinExchange::trim(const std::string& s) {
    const char* ws = " \t\n\r\f\v";
    size_t start = s.find_first_not_of(ws);
    if (start == std::string::npos)
        return std::string();
    size_t end = s.find_last_not_of(ws);
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::IsValidDate(std::string date) {
    date = trim(date);
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    // YYYY-MM-DD positions
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
    }
    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());
    if (m < 1 || m > 12) return false;
    int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    int maxd = mdays[m];
    if (m == 2 && leap)
        maxd = 29;
    if (d < 1 || d > maxd) return false;
    return true;
}
