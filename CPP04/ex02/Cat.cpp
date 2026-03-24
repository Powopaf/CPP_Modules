#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Meow") {
	name = "";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const std::string name) : Animal("Meow") {
	this->name = name;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	name = copy.name;
	type = copy.type;
	brain = new Brain(*copy.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		name = other.name;
		type = other.type;
		*brain = *other.brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
