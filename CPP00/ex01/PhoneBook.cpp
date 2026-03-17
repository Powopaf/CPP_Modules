#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

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

static bool readField(const std::string &prompt, std::string &value) {
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, value)) {
			return false;
		}
	} while (value.empty());
	return true;
}

void PhoneBook::addContact(int index) {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (!readField("Enter first name: ", firstName)
		|| !readField("Enter last name: ", lastName)
		|| !readField("Enter nickname: ", nickname)
		|| !readField("Enter phone number: ", phoneNumber)
		|| !readField("Enter darkest secret: ", darkestSecret)) {
		return;
	}
	this->contacts[index % MAX_CONTACTS] = Contact(firstName, lastName,
		nickname, phoneNumber, darkestSecret);
}

void PhoneBook::searchContact() const {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (contacts[i].getFirstName().length() == 0) {
			continue;
		}
		if (contacts[i].getFirstName().length() < 11) {
			std::cout << contacts[i].getFirstName() << "|";
		} else {
			std::cout << contacts[i].getFirstName().substr(0, 9) << ".|";
		}
	}
	std::cout << std::endl;
	std::string input;
	do {
		std::cout << "Enter index to display: ";
		std::cin >> input;
		if (std::cin.eof()) {
			return;
		}
	} while (input.empty() || !isDigits(input));
	int idx = std::stoi(input);
	if (idx < 0 || idx >= MAX_CONTACTS) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (contacts[idx].getFirstName().length() == 0) {
		std::cout << "No contact at this index." << std::endl;
		return;
	}
	contacts[idx].display();
}
