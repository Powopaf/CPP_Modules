#include "RNP.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error got: " << argc << " args need 2" << std::endl;
    }
    try {
        Rnp rnp(argv[1]);
        std::cout << argv[1] << " = " << rnp.solve() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}