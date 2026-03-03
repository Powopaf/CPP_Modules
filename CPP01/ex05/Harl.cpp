#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "Debug" << std::endl;
}

void Harl::info(void) {
	std::cout << "Info" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Warning" << std::endl;
}

void Harl::error(void) {
	std::cout << "Error" << std::endl;
}

void Harl::complain(std::string level) {
	std::string h_lvl[4] = { "Debug", "Info", "Warning", "Error" };
	void (Harl::*action[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++) {
		if (h_lvl[i] == level) {
			(this->*action[i])();
			break;
		}
	}
}


