#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Must provide a file for program to run" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc(argv[1]);
        std::cout << btc << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}