#include "Zombie.hpp"

int main() {
	Zombie* zom = newZombie("zom");
	randomChump("chump");
	zom->announce();
	delete zom;
	return 0;
}
