#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
	private:
		std::string name;
		Brain* brain;
	public:
		Dog();
		Dog(const std::string name);
		Dog(const Dog& copy);
		virtual ~Dog();
		Dog& operator=(const Dog& other);
		virtual void makeSound() const;
};

#endif
