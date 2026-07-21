#ifndef RNP_HPP
#define RNP_HPP

#include <exception>
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
    std::string convert();

    class BadChar : public std::exception {
        public:
        const char* what() const throw() {
            return "Error: Bad char in input string";
        }
    };
    class BadSyntax : public std::exception {
        public:
            const char* what() const throw() {
                return "Error: bad RPN syntax";
            }
    };
};

#endif