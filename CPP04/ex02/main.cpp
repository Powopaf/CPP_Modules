#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	std::cout << "--- Abstract class demo ---" << std::endl;
	std::cout << "Animal cannot be instantiated directly because makeSound is pure virtual." << std::endl;
	std::cout << "(Uncomment the next line to see compile error)" << std::endl;
	//Animal impossible;

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
