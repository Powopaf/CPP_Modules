#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== ClapTrap Tests ===" << std::endl;
	{
		ClapTrap a = ClapTrap();
		a.attack("Ruby");
		a.takeDamage(5);
		a.beRepaired(3);
	}
	{
		ClapTrap b = ClapTrap("Bob");
		b.attack("Alice");
		b.takeDamage(12);
		b.beRepaired(5);
	}
	{
		ClapTrap c = ClapTrap("Charlie");
		c.attack("Dave");
		c.takeDamage(8);
		c.beRepaired(10);
	}
	{
		ClapTrap d = ClapTrap("Dave");
		d.takeDamage(15);
		d.attack("Charlie");
		d.beRepaired(20);
	}
	{
		ClapTrap e = ClapTrap("Eve");
		for (int i = 0; i < 12; i++) {
			e.attack("Frank");
		}
		e.takeDamage(5);
		e.beRepaired(3);
	}
	std::cout << "\n=== ScavTrap Tests ===" << std::endl;
	{
		ScavTrap scav("Scavvy");
		scav.attack("a target");
		scav.takeDamage(30);
		scav.beRepaired(20);
		scav.guardGate();
	}
	{
		ScavTrap scav2("Scavvy2");
		scav2.attack("another target");
		scav2.takeDamage(50);
		scav2.beRepaired(40);
		scav2.guardGate();
	}
	{
		ScavTrap scav3("Scavvy3");
		scav3.attack("yet another target");
		scav3.takeDamage(70);
		scav3.beRepaired(60);
		scav3.guardGate();
	}
	std::cout << "\n=== FragTrap Tests ===" << std::endl;
	{
		FragTrap frag("Fraggy");
		frag.attack("a target");
		frag.takeDamage(30);
		frag.beRepaired(20);
		frag.highFivesGuys();
	}
	{
		FragTrap frag2("Fraggy2");
		frag2.attack("another target");
		frag2.takeDamage(50);
		frag2.beRepaired(40);
		frag2.highFivesGuys();
	}
	{
		FragTrap frag3("Fraggy3");
		frag3.attack("yet another target");
		frag3.takeDamage(70);
		frag3.beRepaired(60);
		frag3.highFivesGuys();
	}
	{
		DiamondTrap diamond("Diamondy");
		diamond.attack("a target");
		diamond.takeDamage(30);
		diamond.beRepaired(20);
		diamond.guardGate();
		diamond.whoAmI();
	}
	{
		DiamondTrap diamond2("Diamondy2");
		diamond2.attack("another target");
		diamond2.takeDamage(50);
		diamond2.beRepaired(40);
		diamond2.highFivesGuys();
		diamond2.whoAmI();
	}
	{
		DiamondTrap diamond3("Diamondy3");
		diamond3.attack("yet another target");
		diamond3.takeDamage(70);
		diamond3.beRepaired(60);
		diamond3.highFivesGuys();
		diamond3.whoAmI();
	}
	return 0;
}
