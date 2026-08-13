#include "PmergeMe.hpp"

static std::vector<int> fusionV(std::vector<int> a, std::vector<int> b) {
	if (a.size() <= 0)
		return b;
	if (b.size() <= 0)
		return a;
	if (a[0] <= b[0]) {
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
	else {
		b.insert(b.end(), a.begin(), a.end());
		return b;
	}
}

std::vector<int> PmergeMe::sortVect(std::vector<int> v) {
	if (v.size() <= 1)
		return v;
	else {
		std::vector<int>::iterator mid = v.begin() + v.size() / 2;
		std::vector<int> left(v.begin(), mid);
		std::vector<int> right(mid, v.end());
		return fusionV(sortVect(left), sortVect(right));
	}
}

static std::deque<int> fusionQ(std::deque<int> a, std::deque<int> b) {
	
}

std::deque<int> PmergeMe::sortQueue(std::deque<int> q) {
	
}
