#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
    private:
        std::vector<int> vect;
        std::deque<int> queue;
        PmergeMe();
    public:
        PmergeMe(const std::string& intput);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe() {}

        void sortVect();
        void sortQueue();
        std::vector<int> getVect() const;
        std::deque<int> getQueue() const;

        class NotADigit {
            public:
            const char* what() const throw() {
                return "Error: input string contain other char than digit";
            }
        };
};

#endif