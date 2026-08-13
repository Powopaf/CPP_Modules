#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
    public:
        static std::vector<int> sortVect(std::vector<int> v);
        static std::deque<int> sortQueue(std::deque<int> d);
	private:
        // Prevent instantiation: declare canonical form special members as private
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
};

#endif
