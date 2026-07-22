#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

PmergeMe::PmergeMe(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        for (size_t i = 0; i < word.size(); i++) {
            if (!std::isdigit(word[i]))
                throw PmergeMe::NotADigit();
        }
        numbers.push_back(std::atoi(word.c_str()));
    }
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    this->numbers = other.numbers;
    return *this;
}

void PmergeMe::sortVect() {
    
}

void PmergeMe::sortArray() {

}

std::vector<int> PmergeMe::getNumbers() const  {
    return numbers;
}

std::ostream& operator<<(std::ostream& out, PmergeMe& pmm) {
    for (size_t i = 0; i < pmm.getNumbers().size(); i++) {
        out << pmm.getNumbers()[i];
        if (i + 1 < pmm.getNumbers().size())
            out << " ";
    }
    return out;
}