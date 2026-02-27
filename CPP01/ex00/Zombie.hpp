#ifndef ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string name;
	
	public:
		void announce(void);
		void setName(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
