#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " has no energy to attack." << std::endl;
		return;
	}
	if (this->getHitPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " is already destroyed and cannot attack." << std::endl;
		return;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " has entered Gate Keeper mode." << std::endl;
}

void ScavTrap::setEnergyPoints(unsigned int energyPoints) {
	ClapTrap::setEnergyPoints(energyPoints);
}
