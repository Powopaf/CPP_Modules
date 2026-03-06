#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	mantissa = 0;
}

Fixed::Fixed(int const num) {
	mantissa = num << exponant;
}

Fixed::Fixed(float const num) {
	mantissa = (int)roundf(num * (1 << exponant));
}

Fixed::Fixed(const Fixed& copy) {
	 *this = copy;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this == &fixed)
		return *this;
	mantissa = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

static float cmp(const Fixed& f1, const Fixed& f2) {
	return f1.toFloat() - f2.toFloat();
}

bool Fixed::operator>(const Fixed& other) const {
	return cmp(*this, other) > 0;
}

bool Fixed::operator<(const Fixed& other) const {
	return cmp(*this, other) < 0;
}

bool Fixed::operator>=(const Fixed& other) const {
	return cmp(*this, other) >= 0;
}

bool Fixed::operator<=(const Fixed& other) const {
	return cmp(*this, other) <= 0;
}

bool Fixed::operator==(const Fixed& other) const {
	return abs(cmp(*this, other)) < 1e-6;
}

bool Fixed::operator!=(const Fixed& other) const {
	return !(*this == other);
}

Fixed operator+(const Fixed& f1, const Fixed f2) {
	return Fixed(f1.toFloat() + f2.toFloat());
}

Fixed operator-(const Fixed& f1, const Fixed f2) {
	return Fixed(f1.toFloat() - f2.toFloat());
}

Fixed operator*(const Fixed& f1, const Fixed f2) {
	Fixed result;
	result.setRawBits((long long)(f1.getRawBits() * f2.getRawBits()) >> Fixed::exponant);
	return result;
}

Fixed operator/(const Fixed& f1, const Fixed f2) {
	Fixed result;
	result.setRawBits((long long)(f1.getRawBits() << Fixed::exponant) / f2.getRawBits());
	return result;
}

Fixed& Fixed::operator++() {
	mantissa++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	mantissa++;
	return temp;
}

Fixed& Fixed::operator--() {
	mantissa--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	mantissa--;
	return temp;
}

int Fixed::getRawBits(void) const {
	return mantissa;
}

void Fixed::setRawBits(int const raw) {
	mantissa = raw;
}

float Fixed::toFloat(void) const {
	return (float)mantissa / (1 << exponant);
}

int Fixed::toInt(void) const {
	return mantissa >> exponant;
}

Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	return (f1 < f2) ? (Fixed&)f1 : (Fixed&)f2;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed& Fixed::max(Fixed f1, Fixed& f2) {
	return (f1 > f2) ? (Fixed&)f1 : f2;
}

Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	return (f1 > f2) ? (Fixed&)f1 : (Fixed&)f2;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

