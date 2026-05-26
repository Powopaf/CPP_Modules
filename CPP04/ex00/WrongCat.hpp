#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		std::string name;
	public:
		WrongCat(const std::string& name);
		WrongCat();
		WrongCat(const WrongCat& copy);
		virtual ~WrongCat();
		WrongCat& operator=(const WrongCat& other);
		void makeSound();
};

#endif