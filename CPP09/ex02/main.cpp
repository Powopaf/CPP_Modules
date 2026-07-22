#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <string>

static std::string createNumbers(char** argv, int argc) {
    std::string res;
    for (int i = 1; i < argc; i++) {
        res += argv[i];
        if (i + 1 < argc)
            res+= " ";
    }
    return res;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: no arg input need 1 at least" << std::endl;
        return 1;
    }
    std::string numbers = createNumbers(argv, argc);
    try {
        PmergeMe pmm(numbers);
        std::cout << "Before: " << pmm << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}