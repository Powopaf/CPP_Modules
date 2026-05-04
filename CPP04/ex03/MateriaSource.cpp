#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	for (int i = 0; i < 4; i++)
		materias[i] = copy.materias[i];
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this == &copy)
		return *this;
	for (int i = 0; i < 4; i++)
		materias[i] = copy.materias[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
