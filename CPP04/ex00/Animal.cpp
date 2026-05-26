#include <iostream>
#include "Animal.hpp"

Animal::Animal(){
	type = "";
}

Animal::Animal(const Animal& copy){
	type = copy.type;
}

Animal::~Animal(){
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void Animal::makeSound() {
	std::cout << "Noises" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
