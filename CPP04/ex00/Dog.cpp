#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	name = "";
	type = "Dog";
}

Dog::Dog(const std::string name) {
	this->name = name;
	type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	name = copy.name;
	type = copy.type;
}

Dog::~Dog() {
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		name = other.name;
		type = other.type;
	}
	return *this;
}

void Dog::makeSound() {
	std::cout << "Woof" << std::endl;
}
