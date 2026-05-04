
#include "Character.hpp"

Character::Character() {
	name = "None";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &copy) {
	name = copy.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = copy.inventory[i];
}

Character::~Character() {}

Character &Character::operator=(const Character &copy) {
	if (this == &copy)
		return *this;
	name = copy.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = copy.inventory[i];
	return *this;
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

std::string const &Character::getName() const {
	return name;
}
