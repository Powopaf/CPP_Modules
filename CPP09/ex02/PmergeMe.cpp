#include "PmergeMe.hpp"

static std::vector<int> fusionV(std::vector<int> a, std::vector<int> b) {
	if (a.size() <= 0)
		return b;
	if (b.size() <= 0)
		return a;
	if (a[0] <= b[0]) {
		std::vector<int> restA(a.begin() + 1, a.end());
		std::vector<int> merged;
		merged.push_back(a[0]);
		std::vector<int> tail = fusionV(restA, b);
		merged.insert(merged.end(), tail.begin(), tail.end());
		return merged;
	}
	else {
		std::vector<int> restB(b.begin() + 1, b.end());
		std::vector<int> merged;
		merged.push_back(b[0]);
		std::vector<int> tail = fusionV(a, restB);
		merged.insert(merged.end(), tail.begin(), tail.end());
		return merged;
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
	if (a.size() <= 0)
		return a;
	if (b .size() <= 0)
		return b;
	if (a[0] <= b[0]) {
		std::deque<int> restA(a.begin() + 1, a.end());
		std::deque<int> merged;
		merged.push_back(a[0]);
		std::deque<int> tail = fusionQ(restA, b);
		merged.insert(merged.end(), tail.begin(), tail.end());
		return merged;
	}
	else {
		std::deque<int> restB(b.begin() + 1, b.end());
		std::deque<int> merged;
		merged.push_back(b[0]);
		std::deque<int> tail = fusionQ(a, restB);
		merged.insert(merged.end(), tail.begin(), tail.end());
		return merged;
	}
}

std::deque<int> PmergeMe::sortQueue(std::deque<int> q) {
	if (q.size() <= 1)
		return q;
	else {
		std::deque<int>::iterator mid = q.begin() + q.size() / 2;
		std::deque<int> left(q.begin(), mid);
		std::deque<int> right(mid, q.end());
		return fusionQ(sortQueue(left), sortQueue(right));
	}
}
