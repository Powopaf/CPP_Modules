#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	type = "WrongCat";
	name = "";
}

WrongCat::WrongCat(const std::string& name) {
	this->name = name;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	type = copy.type;
	name = copy.name;
}

WrongCat::~WrongCat() {
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		type = other.type;
		name = other.name;
	}
	return *this;
}

void WrongCat::makeSound() {
	std::cout << "WrongCat sound" << std::endl;
}