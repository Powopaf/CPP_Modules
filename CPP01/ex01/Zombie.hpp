#ifndef ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string name;
	
	public:
		void announce(void);
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
