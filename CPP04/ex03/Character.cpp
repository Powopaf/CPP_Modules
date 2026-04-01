#include "Character.hpp"

ICharacter::ICharacter() {
	name = "";
	for (int i = 0; i < inventorySize; i++) {
		inventory[i] = nullptr;
	}
}
