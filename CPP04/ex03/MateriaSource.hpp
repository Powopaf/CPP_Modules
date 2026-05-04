#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &copy);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};
