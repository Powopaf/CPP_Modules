#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void) {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else
    std::cout << "Class C" << std::endl;
}

void Base::identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Class A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Class B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Class C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

}