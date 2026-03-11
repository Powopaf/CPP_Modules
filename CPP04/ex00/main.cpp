#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	{
		Cat cat("Whiskers");
		Dog dog("Rex");

		std::cout << "Cat type: " << cat.getType() << std::endl;
		std::cout << "Dog type: " << dog.getType() << std::endl;

		std::cout << "Cat sound: ";
		cat.makeSound();
		std::cout << "Dog sound: ";
		dog.makeSound();
	}
	return 0;
}
