#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private:
		std::string name;
	public:
		Cat();
		Cat(const std::string name);
		Cat(const Cat& copy);
		virtual ~Cat();
		Cat& operator=(const Cat& other);
};

#endif
