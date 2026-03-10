#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		virtual ~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
		void setEnergyPoints(unsigned int energyPoints);
};

#endif
