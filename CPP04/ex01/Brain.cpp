#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	for (int i = 0; i < Brain::numIdeas; i++) {
		ideas[i] = "";
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < Brain::numIdeas; i++) {
		ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
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

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < Brain::numIdeas) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < Brain::numIdeas) {
		return ideas[index];
	}
	return "";
}
