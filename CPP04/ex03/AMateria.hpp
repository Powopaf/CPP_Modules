#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	private:
		std::string type;
	protected:
	public:
		AMateria();
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &copy);
		AMateria(std::string const &type);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
