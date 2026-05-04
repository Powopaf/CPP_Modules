
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

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}
