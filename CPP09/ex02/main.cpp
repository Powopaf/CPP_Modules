#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
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

static std::vector<int> init_vect(const std::string& nums) {
    std::vector<int> values;
    std::istringstream stream(nums);
    std::string token;

    while (stream >> token) {
        for (std::string::size_type i = 0; i < token.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
                std::cerr << "Error: invalid input" << std::endl;
                std::exit(1);
            }
        }
        values.push_back(std::atoi(token.c_str()));
    }
    return values;
}

static std::deque<int> init_queue(const std::string& nums) {
	std::deque<int> values;
	std::istringstream stream(nums);
	std::string token;

	while (stream >> token) {
		for (std::string::size_type i = 0; i < token.size(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
				std::cerr << "Error: invalid input" << std::endl;
				std::exit(1);
			}
		}
		values.push_back(std::atoi(token.c_str()));
	}
	return values;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: no arg input need 1 at least" << std::endl;
        return 1;
    }
    std::string numbers = createNumbers(argv, argc);
	std::vector<int> vect = init_vect(numbers);
	std::deque<int> queue = init_queue(numbers);
	return 0;
}
