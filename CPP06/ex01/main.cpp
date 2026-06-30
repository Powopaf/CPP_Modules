#include "Serializer.hpp"
#include <iostream>

int main() {
	Data a(1, 'c');
	std::cout << "int: " << a.getI() << ", char: " << a.getC() << std::endl;
	uintptr_t p = Serializer::serialize(&a);
	std::cout << p << std::endl;
	Data* b = Serializer::deserialize(p);
	std::cout << "int: " << b->getI() << ", char: " << b->getC() << std::endl;
	return 0;
}
