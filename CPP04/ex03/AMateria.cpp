#include "AMateria.hpp"

AMateria::AMateria() {
	type = "None";
}

AMateria::AMateria(const AMateria &copy) {
	type = copy.type;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &copy) {
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

AMateria::AMateria(std::string const &type) {
	this->type = type;
}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
