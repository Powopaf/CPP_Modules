#include <iostream>
#include "Animal.hpp"

Animal::Animal(){
	type = "";
	sound = "";
}

Animal::Animal(const std::string& sound) {
	this->type = "";
	this->sound = sound;
}

Animal::Animal(const Animal& copy){
	type = copy.type;
	sound = copy.sound;
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

std::string Animal::getType() const {
	return type;
}
