#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
    private:
        unsigned int limit;
        std::vector<int> v;
        Span();
    public:
        Span(unsigned int limit);
        Span(const Span& copy);
        Span& operator=(const Span& other);
        ~Span() {}

        void addNumber(int a);
        int shortestSpan();
        int longestSpan();
        void fill();

        class NoPlaceException : public std::exception {
            public:
                const char* what() const throw() {
                    return "There is no place left int the vector";
                }
        };

        class NoSpanException : public std::exception {
            public:
                const char* what() const throw() {
                    return "No Span can be found";
                }
        };
};

#endif