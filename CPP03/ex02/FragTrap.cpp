#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called for " << copy.getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap copy assignment operator called for " << copy.getName() << std::endl;
	if (this == &copy)
		return *this;
	ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << this->getName() << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->getName() << " is requesting a high five!" << std::endl;
}
