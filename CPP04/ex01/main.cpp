#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	{
		std::cout << "Test 1: deep copy" << std::endl;
		Dog originalDog("Buddy");
		Dog copiedDog(originalDog);
		Cat originalCat("Milo");
		Cat copiedCat(originalCat);

		originalDog.getBrain()->setIdea(0, "fetch");
		copiedDog.getBrain()->setIdea(0, "sleep");
		originalCat.getBrain()->setIdea(0, "hunt");
		copiedCat.getBrain()->setIdea(0, "nap");

		std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Original cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied cat idea: " << copiedCat.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n";

	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = size / 2; i < size; i++) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	return 0;
}
