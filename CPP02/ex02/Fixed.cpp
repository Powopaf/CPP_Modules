#include "Fixed.hpp"
#include <ostream>
#include <cmath>

Fixed::Fixed() {
	mantissa = 0;
}

Fixed::Fixed(int const num) {
	mantissa = num;
}

Fixed::Fixed(float const num) {
	mantissa = (int)roundf(num * (1 << exponant));
}

Fixed::Fixed(Fixed& copy) {
	 *this = copy;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this == &fixed)
		return *this;
	mantissa = fixed.getRawBits();
	return *this;
}

static float cmp(const Fixed& f1, const Fixed& f2) {
	return f1	
}

bool Fixed::operator>(const Fixed& other) const {
	float cmp = this->toFloat() - other.toFloat();
	return cmp > 0;
}

bool Fixed::operator<(const Fixed& other) const {
	float cmp = this->toFloat() - other.toFloat();
	return cmp < 0; 
}

bool Fixed::operator>=(const Fixed& other) const {
	float
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
