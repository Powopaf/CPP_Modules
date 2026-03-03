#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\n" << std::endl;
}

static int index_level(std::string level) {
	std::string h_lvl[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (int i = 0; i < 4; i++) {
		if (h_lvl[i] == level)
			return i;
	}
	return -1;
}

void Harl::complain(std::string level) {
	switch (index_level(level)) {
		case 0:
			debug();
			/* fall through */
		case 1:
			info();
			/* fall through */
		case 2:
			warning();
			/* fall through */
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	};
}
