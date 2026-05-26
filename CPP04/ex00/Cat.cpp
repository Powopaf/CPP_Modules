#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	name = "";
	type = "Cat";
}

Cat::Cat(const std::string name) {
	this->name = name;
	type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	name = copy.name;
	type = copy.type;
}

Cat::~Cat() {
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		name = other.name;
		type = other.type;
	}
	return *this;
}

void Cat::makeSound() {
	std::cout << "Meow" << std::endl;
}