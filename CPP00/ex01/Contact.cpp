#include "Contact.hpp"

Contact::Contact() {
	this->name = "";
	this->id = 0;
}

Contact::Contact(std::string name, int id) {
	this->name = name;
	this->id = id;
}

std::string Contact::getName() const {
	return this->name;
}

int Contact::getId() const {
	return this->id;
}
