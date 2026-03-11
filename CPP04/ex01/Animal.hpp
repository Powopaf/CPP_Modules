#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	private:
		std::string sound;
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& sound);
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal& operator=(const Animal& other);

		void makeSound();
		std::string getType() const;
};

#endif
