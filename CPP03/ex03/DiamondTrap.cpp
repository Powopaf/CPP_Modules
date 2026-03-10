#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	DiamondTrap::name = "Default";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap parameterized constructor called for " << name << std::endl;
	DiamondTrap::name = name;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap copy constructor called for " << copy.name << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assignment operator called for " << copy.name << std::endl;
	if (this == &copy)
		return *this;
	ClapTrap::operator=(copy);
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
