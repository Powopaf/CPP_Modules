#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
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
        vect.push_back(std::atoi(word.c_str()));
        queue.push_back(std::atoi(word.c_str()));
    }
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    this->vect = other.vect;
    this->queue = other.queue;
    return *this;
}

void PmergeMe::sortVect() {
    
}

void PmergeMe::sortQueue() {

}

std::vector<int> PmergeMe::getVect() const  {
    return vect;
}

std::deque<int> PmergeMe::getQueue() const {
    return queue;
}