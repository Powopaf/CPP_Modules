#include <iostream>
#include "Animal.hpp"

Animal::Animal(){
	type = "";
	sound = "";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& sound) {
	this->type = "";
	this->sound = sound;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy){
	type = copy.type;
	sound = copy.sound;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
		sound = other.sound;
	}
	return *this;
}

void Animal::makeSound() {
	std::cout << sound << std::endl;
}

std::string Animal::getType() const {
	return type;
}
