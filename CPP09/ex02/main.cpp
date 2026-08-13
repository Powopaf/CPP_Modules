#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

static void printValues(const std::vector<int>& values) {
    for (std::vector<int>::size_type i = 0; i < values.size(); ++i) {
        std::cout << values[i];
        if (i + 1 < values.size())
            std::cout << ' ';
    }
    std::cout << std::endl;
}

static void printValues(const std::deque<int>& values) {
    for (std::deque<int>::size_type i = 0; i < values.size(); ++i) {
        std::cout << values[i];
        if (i + 1 < values.size())
            std::cout << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: no arg input need 1 at least" << std::endl;
        return 1;
    }
    std::string numbers = createNumbers(argv, argc);
	std::vector<int> vect = init_vect(numbers);
	std::deque<int> queue = init_queue(numbers);

    std::cout << "Before: " << numbers << std::endl;

    clock_t vectStart = clock();
	std::vector<int> sortedVect = PmergeMe::sortVect(vect);
    clock_t vectEnd = clock();

    clock_t queueStart = clock();
	std::deque<int> sortedQueue = PmergeMe::sortQueue(queue);
    clock_t queueEnd = clock();

    std::cout << "After: ";
    printValues(sortedVect);
    std::cout << "After: ";
    printValues(sortedQueue);

    double vectTime = static_cast<double>(vectEnd - vectStart) * 1000000.0 / CLOCKS_PER_SEC;
    double queueTime = static_cast<double>(queueEnd - queueStart) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vect.size()
              << " elements with std::vector : " << vectTime << " us" << std::endl;
    std::cout << "Time to process a range of " << queue.size()
              << " elements with std::deque : " << queueTime << " us" << std::endl;

	return 0;
}
