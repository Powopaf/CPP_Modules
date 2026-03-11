#include "Dog.hpp"

Dog::Dog() : Animal("Woof") {
	name = "";
	type = "Dog";
}

Dog::Dog(const std::string name) : Animal("Woof") {
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
