#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>

Span::Span(unsigned int limit) {
    this->limit = limit;
    v.reserve(this->limit);
}

Span::Span(const Span& copy) {
    limit = copy.limit;
    v = copy.v;
}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    this->limit = other.limit;
    this->v = other.v;
    return *this;
}

void Span::addNumber(int a) {
    if (v.size() >= limit)
        throw NoPlaceException();
    v.push_back(a);
}

void Span::fill() {
    for (unsigned int i = 0; i < limit; i++) {
        v.push_back(i);
    }
}

int Span::shortestSpan() {
    if (v.size() < 2)
        throw NoSpanException();
    std::vector<int> s = v;
    std::sort(s.begin(), s.end());
    int res = INT_MAX;
    for (size_t i = 0; i < s.size() - 1; i++) {
        int diff = s[i + 1] - s[i];
            if (diff < res)
                res = diff;
    }
    return res;
}

int Span::longestSpan() {
    if (v.size() < 2)
        throw NoSpanException();
    std::vector<int> s = v;
    std::sort(s.begin(), s.end());
    return s.back() - s.front();
}