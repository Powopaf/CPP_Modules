#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	name = "";
}

Zombie::Zombie(const Zombie& other) {
	*this = other;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Destroy: " << this->name << std::endl;
}
