#include "PhoneBook.hpp"
#include <iostream>

static void init(PhoneBook* phoneBook) {
	*phoneBook = PhoneBook();
	for (int i = 0; i < 8; i++) {
		phoneBook->contacts[i] = Contact();
		phoneBook->contacts[i].id = -1;
	}
}

static void add(PhoneBook* phoneBook, int to_change) {
	int id = -1;
	std::string name;
	std::cout << "Adding a contact enter id then name (less than 10 characters)" << std::endl;
	std::cout << "id: "; std::cin >> id;
	std::cout << "name: "; std::cin >> name;
	for (int i = 0; i < 8; i++) {
		if (phoneBook->contacts[i].id == id) {
			std::cout << "Contact with this id already exists. Please try again." << std::endl;
			return;
		}
	}
	phoneBook->contacts[to_change % 8].id = id;
	phoneBook->contacts[to_change % 8].name = name.substr(0, 10);
}

static void search(PhoneBook phoneBook) {
	int id;
	std::string name;
	std::cout << "Enter 1 to search with id or 2 to search with name: " << std::endl;
	std::cin >> id;
	if (id == 1) {
		std::cout << "Enter id: ";
		std::cin >> id;
		for (int i = 0; i < 8; i++) {
			if (phoneBook.contacts[i].id == id) {
				std::cout << "Contact found: id: " << phoneBook.contacts[i].id << std::endl 
					<< " name: " << phoneBook.contacts[i].name << std::endl;
				return;
			}
		}
		std::cout << "Contact not found." << std::endl;
	} else if (id == 2) {
		std::cout << "Enter name: ";
		std::cin >> name;
		for (int i = 0; i < 8; i++) {
			if (!phoneBook.contacts[i].name.empty()) {
				if (phoneBook.contacts[i].name == name) {
					std::cout << "Contact found: id: " << phoneBook.contacts[i].id << std::endl
						<<" name: " << phoneBook.contacts[i].name << std::endl;
					return;
				}
			}
		}
		std::cout << "Contact not found." << std::endl;
	} else {
		std::cout << "Invalid search type." << std::endl;
	}
}

int main() {
	int to_change = 0;
	PhoneBook phoneBook;
	init(&phoneBook);
	std::string input;
	std::cout << "ADD: to add a contact to the phonebook" << std::endl;
	std::cout << "SEARCH: to display a contact from the phonebook" << std::endl;
	std::cout << "EXIT: to close the phonebook" << std::endl;
	std::cout << "wait for command: ";
	std::cin >> input;
	while (input != "EXIT") {
		if (input == "ADD") {
			add(&phoneBook, to_change);
			to_change++;
		} else if (input == "SEARCH") {
			search(phoneBook);
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}
		std::cout << "wait for new command: ";
		std::cin >> input;
	}
	return 0;
}
