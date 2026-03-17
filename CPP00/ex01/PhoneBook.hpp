#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
	public:
		PhoneBook();
		void addContact(int index);
		void searchContact() const;
};

#endif
