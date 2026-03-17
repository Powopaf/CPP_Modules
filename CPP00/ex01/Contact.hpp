#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string name;
		int id;
	public:
		Contact();
		Contact(std::string name, int id);
		std::string getName() const;
		int getId() const;
};

#endif
