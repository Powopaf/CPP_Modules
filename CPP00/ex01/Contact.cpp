#include "Contact.hpp"

#include <iostream>

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
	const std::string &nickname, const std::string &phoneNumber,
	const std::string &darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
	return this->firstName;
}

std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}

void Contact::display() const {
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
}
