#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ScavTrap scav("Scavvy");
	scav.attack("a target");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	return 0;
}
