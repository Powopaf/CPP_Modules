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
	std::cin >> input;
	while (input != "EXIT") {
		if (input == "ADD") {
			phoneBook.addContact(to_change);
			to_change++;
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}
		std::cout << "wait for new command: ";
		std::cin >> input;
	}
	return 0;
}
