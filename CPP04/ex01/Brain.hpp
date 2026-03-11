#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	private:
		static const int numIdeas = 100;
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		virtual ~Brain();
		Brain& operator=(const Brain& other);
};

#endif
