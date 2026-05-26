#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	std::cout << "--- Abstract Animal test ---" << std::endl;
	std::cout << "Animal is abstract: direct instantiation must fail." << std::endl;
	//Animal a = Animal(); // This should fail to compile

	std::cout << "\nTest: polymorphism through Animal pointers" << std::endl;
	Animal* zoo[4];
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog("Rex");
	zoo[3] = new Cat("Milo");

	for (int index = 0; index < 4; index++) {
		std::cout << "type: " << zoo[index]->getType() << " -> sound: ";
		zoo[index]->makeSound();
	}

	for (int index = 0; index < 4; index++) {
		delete zoo[index];
	}

	return 0;
}
