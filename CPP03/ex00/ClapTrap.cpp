#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	name = "Default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) {
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	if (this == &copy)
		return *this;
	name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy to attack." << std::endl;
		return;
	}
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed and cannot attack." << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage." << std::endl;
		return;
	}
	hitPoints = amount >= hitPoints ? 0 : hitPoints - amount;
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy to repair." << std::endl;
		return;
	}
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed and cannot be repaired." << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! Current hit points: " << hitPoints << std::endl;
}
