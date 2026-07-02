#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing identify with pointers ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        Base* obj = new Base();
        Base* random_obj = obj->generate();
        std::cout << "Object " << i + 1 << ": ";
        random_obj->identify(random_obj);
        delete random_obj;
    }

    std::cout << "\n=== Testing identify with references ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        Base* random_obj = new Base();
        random_obj = random_obj->generate();
        std::cout << "Object " << i + 1 << ": ";
        random_obj->identify(*random_obj);
        delete random_obj;
    }

    return 0;
}