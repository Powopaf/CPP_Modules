#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character();
		Character(const Character &copy);
		virtual ~Character();
		Character &operator=(const Character &copy);
		Character(std::string name);

		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};
