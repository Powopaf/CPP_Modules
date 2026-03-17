#include "PhoneBook.hpp"
#include <iostream>

int main() {
	int to_change = 0;
	PhoneBook phoneBook;
	std::string input;
	std::cout << "ADD: to add a contact to the phonebook" << std::endl;
	std::cout << "SEARCH: to display a contact from the phonebook" << std::endl;
	std::cout << "EXIT: to close the phonebook" << std::endl;
	std::cout << "wait for command: ";
	do {
		std::cin >> input;
		if (std::cin.eof()) {
			break;
		}
		if (input == "ADD") {
			phoneBook.addContact(to_change);
			to_change++;
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else if (input == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}
		std::cout << "wait for new command: ";
	} while (1);
	return 0;
}
