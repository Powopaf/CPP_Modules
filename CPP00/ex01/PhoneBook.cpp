#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		this->contacts[i] = Contact();
	}
}

static bool isDigits(const std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void PhoneBook::addContact(int index) {
	std::cout << "Enter name: ";
	std::string name;
	std::cin >> name;
	std::string id;
	do {
		std::cout << "Enter id: ";
		std::cin >> id;
	} while (id.empty() || !isDigits(id));
	this->contacts[index % MAX_CONTACTS] = Contact(name, std::stoi(id));
}

void PhoneBook::searchContact() const {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (contacts[i].getName().length() == 0) {
			continue;
		}
		if (contacts[i].getName().length() < 11) {
			std::cout << contacts[i].getName() << "|";
		} else {
			std::cout << contacts[i].getName().substr(0, 9) << ".|";
		}
	}
	std::cout << std::endl;
	std::string input;
	do {
		std::cout << "Enter index to display: ";
		std::cin >> input;
	} while (input.empty() || !isDigits(input));
	int idx = std::stoi(input);
	if (idx < 0 || idx >= MAX_CONTACTS) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (contacts[idx].getName().length() == 0) {
		std::cout << "No contact at this index." << std::endl;
		return;
	}
	std::cout << "Name: " << contacts[idx].getName() << std::endl;
	std::cout << "ID: " << contacts[idx].getId() << std::endl;
}
