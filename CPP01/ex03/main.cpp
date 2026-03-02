#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void) {
	{
		Weapon knife = Weapon("knife");
		HumanA bob("Bob", knife);
		bob.attack();
		knife.setType("ruler");
		bob.attack();
	}
	{
		Weapon club = Weapon("club");
		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("baseball bat");
		jim.attack();
	}
	return 0;
}
