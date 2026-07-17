#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cmath>
#include <climits>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

static void find_rate(std::string file_name, BitcoinExchange& btc);

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Must provide a file for program to run" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        find_rate(argv[1], btc);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

static void find_rate(std::string file_name, BitcoinExchange& btc) {
    std::multimap<std::string, double> db = btc.getDb();
    std::ifstream file(file_name.c_str(), std::ios::in);
    if (!file.is_open())
        throw std::runtime_error("Error: Can't open file: " + file_name);
    std::string line;
    if (!std::getline(file, line))
        return;
    if (line != "date | value")
        throw std::runtime_error("Error: Bad Header in " + file_name);
    while (std::getline(file, line)) {
        line = btc.trim(line);
        size_t pipe_idx = line.find('|');
        if (pipe_idx == std::string::npos) {
            std::cerr << "Error: Bad input => " + line << std::endl;
            continue;
        }
        std::string date = btc.trim(line.substr(0, pipe_idx));
        if (!btc.IsValidDate(date)) {
            std::cerr << "Error: bad Date: " + date << std::endl;
            continue;
        }
        std::string rate_str = btc.trim(line.substr(pipe_idx + 1));
        errno = 0;
        char *endptr = NULL;
        double rate = std::strtod(rate_str.c_str(), &endptr);
        if (endptr == rate_str.c_str()) {
            std::cerr << "Error: bad number => " << rate_str << std::endl;
            continue;
        }
        else if (errno == ERANGE || !std::isfinite(rate) || rate > INT_MAX) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        else if (rate < 0.0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        std::multimap<std::string, double>::const_iterator it = db.lower_bound(date);
        if (it != db.end())
            std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
        else {
            std::cerr << "Error: No matching date: " << date << std::endl;
        }
    }
}