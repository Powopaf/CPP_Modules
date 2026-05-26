#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Woof") {
	name = "";
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string name) : Animal("Woof") {
	this->name = name;
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	name = copy.name;
	type = copy.type;
	brain = new Brain(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		name = other.name;
		type = other.type;
		*brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound() {
	std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}
