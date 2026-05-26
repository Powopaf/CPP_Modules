#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	type = copy.type;
}

WrongAnimal::~WrongAnimal() {
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() {
	std::cout << "Noises" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}