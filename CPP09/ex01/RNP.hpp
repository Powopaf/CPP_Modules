#ifndef RNP_HPP
#define RNP_HPP

#include <exception>
#include <stack>
#include <string>

class Rnp {
    private:
    std::string operation;
    Rnp();

    public:
    Rnp(const std::string& operation);
    Rnp(const Rnp& copy);
    Rnp& operator=(const Rnp& other);
    ~Rnp() {}

    int solve();

    class BadChar : public std::exception {
        public:
        const char* what(char c) const throw() {
            return "Error: Bad char in input string: " + c;
        }
    };
};

#endif