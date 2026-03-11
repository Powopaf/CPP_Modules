#include "Cat.hpp"

Cat::Cat() : Animal("Meow") {
	name = "";
	type = "Cat";
}

Cat::Cat(const std::string name) : Animal("Meow") {
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
