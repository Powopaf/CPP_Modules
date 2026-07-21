#include "RNP.hpp"
#include <cstddef>

static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Rnp::Rnp(const std::string& operation) {
    for (size_t i  = 0; i < operation.size(); i++) {
        if (operation[i] < '0' && operation[i] > '9' 
            && !isOperator(operation[i]))
            throw Rnp::BadChar();
    }
}

Rnp::Rnp(const Rnp& copy) {
    *this = copy;
}

Rnp& Rnp::operator=(const Rnp& other) {
    if (this == &other)
        return *this;
    this->operation = other.operation;
    return *this;
}

int Rnp::solve() {
    return 0;
}