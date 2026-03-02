#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type = "sword");
		const std::string& getType();
		void setType(const std::string type);
};

#endif
