#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ostream>
#include <string>
#include <vector>

class PmergeMe {
    private:
        std::vector<int> numbers;
        PmergeMe();
    public:
        PmergeMe(const std::string& intput);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe() {}

        void sortVect();
        void sortArray();
        std::vector<int> getNumbers() const;

        class NotADigit {
            public:
            const char* what() const throw() {
                return "Error: input string contain other char than digit";
            }
        };
};

std::ostream& operator<<(std::ostream& out, PmergeMe& pmm);

#endif