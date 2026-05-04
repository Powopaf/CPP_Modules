#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		Ice &operator=(const Ice &copy);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
}
