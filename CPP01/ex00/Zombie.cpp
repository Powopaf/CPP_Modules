#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
	std::cout << name << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
