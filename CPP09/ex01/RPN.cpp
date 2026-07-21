#include "RNP.hpp"
#include <cctype>
#include <cstddef>
#include <stack>
#include <string>

static bool isoperator(unsigned char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Rnp::Rnp(const std::string& operation) {
    int size = 0;
    for (size_t i  = 0; i < operation.size(); i++) {
        if (std::isspace(static_cast<unsigned char>(operation[i])))
            continue;
        else if (std::isdigit(static_cast<unsigned char>(operation[i])))
            size++;
        else if (isoperator(static_cast<unsigned char>(operation[i]))) {
            if (size < 2)
                throw Rnp::BadSyntax();
            size--;
        }
        else
            throw Rnp::BadChar();
    }
    if (size != 1)
        throw Rnp::BadSyntax();
    this->operation = operation;
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
    std::stack<int> s;
    for (size_t i  = 0; i < operation.size(); i++) {
        if (std::isspace(static_cast<unsigned char>(operation[i])))
            continue;
        if (std::isdigit(operation[i]))
            s.push(operation[i] - '0');
        else {
            int num = s.top(); s.pop();
            int num2 = s.top(); s.pop();
            switch (operation[i]) {
                case '+':
                    s.push(num + num2);
                    break;
                case '-':
                    s.push(num2 - num);
                    break;
                case '*':
                    s.push(num * num2);
                    break;
                case '/':
                    s.push(num2 / num);
                    break;
                default:
                    ;
            }
        }
    }
    return s.top();
}


std::string Rnp::convert() {
    std::stack<std::string> s;
    for (size_t i  = 0; i < operation.size(); i++) {
        if (std::isspace(static_cast<unsigned char>(operation[i])))
            continue;
        if (std::isdigit(operation[i]))
            s.push(std::string(1, operation[i]));
        else {
                std::string a = s.top(); s.pop();
                std::string b = s.top(); s.pop();
                std::string expr = "(" + a + operation[i] + b + ")";
                s.push(expr);
            }
        }
    return s.top();
}