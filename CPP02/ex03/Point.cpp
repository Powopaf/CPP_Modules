#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}

Point& Point::operator=(const Point& copy) {
	if (this == &copy)
		return *this;
	(Fixed&)x = copy.x;
	(Fixed&)y = copy.y;
	return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const {
	return x;
}

const Fixed& Point::getY() const {
	return y;
}