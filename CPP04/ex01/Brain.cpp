#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	for (int i = 0; i < Brain::numIdeas; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < Brain::numIdeas; i++) {
		ideas[i] = copy.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < Brain::numIdeas; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
