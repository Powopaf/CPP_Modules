#ifndef Character_HPP
#define Character_HPP

#include <string>

class AMateria;

class ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];
		static const int inventorySize = 4;
	public:
		ICharacter();
		ICharacter(const std::string& name);
		virtual ~ICharacter() {}
		ICharacter(const ICharacter& other);
		ICharacter& operator=(const ICharacter& other);

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
