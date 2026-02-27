#include "Zombie.hpp"

int main(void) {
	Zombie* zom = newZombie("zom");
	randomChump("chump");
	zom->announce();
	delete zom;
	return 0;
}
