#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	fix_num = num << bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	fix_num = (int)(num * (1 << bits));
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	fix_num = 0;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	fix_num = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fix_num;
}

void Fixed::setRawBits(int const raw) {
	fix_num = raw;
}

float Fixed::toFloat(void) const {
	return (float)fix_num / (1 << bits);
}

int Fixed::toInt(void) const {
	return (int)fix_num >> bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
