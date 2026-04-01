#include "AMateria.hpp"

AMateria::AMateria() {
	type = "";
}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return type;
}
