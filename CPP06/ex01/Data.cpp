#include "Data.hpp"

Data::Data() {
    i = 0;
    c = 0;
}

Data::Data(int i, char c) {
    this->i = i;
    this->c = c;
}

Data::Data(const Data& copy) {
    *this = copy;
}

Data& Data::operator=(const Data& other) {
    if (this == &other)
        return *this;
    i = other.i;
    c = other.c;
    return *this;
}

int Data::getI() const {
    return i;
}

char Data::getC() const {
    return c;
}