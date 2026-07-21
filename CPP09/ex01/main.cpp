#include "RNP.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error got: " << argc << " args need 2" << std::endl;
        return 1;
    }
    try {
        Rnp rpn(argv[1]);
        std::cout << rpn.convert() << " = " << rpn.solve() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}