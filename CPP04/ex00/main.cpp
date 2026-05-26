#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	{
		std::cout << "Test 1: direct objects" << std::endl;
		Cat cat("Whiskers");
		Dog dog("Rex");

		std::cout << "Cat type: " << cat.getType() << std::endl;
		std::cout << "Dog type: " << dog.getType() << std::endl;

		std::cout << "Cat sound: ";
		cat.makeSound();
		std::cout << "Dog sound: ";
		dog.makeSound();
	}

	std::cout << "\n";

	{
		std::cout << "Test 2: copy constructor and assignment" << std::endl;
		Cat originalCat("Milo");
		Cat copiedCat(originalCat);
		Dog originalDog("Buddy");
		Dog assignedDog;
		assignedDog = originalDog;

		std::cout << "Original cat type: " << originalCat.getType() << std::endl;
		std::cout << "Copied cat type: " << copiedCat.getType() << std::endl;
		std::cout << "Original dog type: " << originalDog.getType() << std::endl;
		std::cout << "Assigned dog type: " << assignedDog.getType() << std::endl;

		std::cout << "Copied cat sound: ";
		copiedCat.makeSound();
		std::cout << "Assigned dog sound: ";
		assignedDog.makeSound();
	}

	std::cout << "\n";

	{
		std::cout << "Test 3: polymorphism through base pointers" << std::endl;
		Animal* animals[3];
		animals[0] = new Cat("Kitty");
		animals[1] = new Dog("Rover");
		animals[2] = new Animal();

		for (int i = 0; i < 3; ++i) {
			std::cout << "Animal type: " << animals[i]->getType() << std::endl;
			std::cout << "Animal sound: ";
			animals[i]->makeSound();
			delete animals[i];
		}
	}

	std::cout << "\n";

	{
		std::cout << "Test 4: wrong objects" << std::endl;
		WrongAnimal wrongAnimal;
		WrongCat wrongCat;

		std::cout << "WrongAnimal type: " << wrongAnimal.getType() << std::endl;
		std::cout << "WrongAnimal sound: ";
		wrongAnimal.makeSound();

		std::cout << "WrongCat type: " << wrongCat.getType() << std::endl;
		std::cout << "WrongCat sound: ";
		wrongCat.makeSound();
	}

	std::cout << "\n";

	{
		std::cout << "Test 5: wrong polymorphism through base pointer" << std::endl;
		WrongAnimal* wrongAnimal = new WrongCat();

		std::cout << "WrongAnimal pointer type: " << wrongAnimal->getType() << std::endl;
		std::cout << "WrongAnimal pointer sound: ";
		wrongAnimal->makeSound();
		delete wrongAnimal;
	}

	return 0;
}
