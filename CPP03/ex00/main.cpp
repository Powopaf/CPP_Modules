#include "ClapTrap.hpp"

int main() {
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
}