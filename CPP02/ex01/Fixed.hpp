#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int fix_num;
		static const int bits = 8;
	public:
		Fixed(const float num);
		Fixed(const int num);
		Fixed();
		Fixed(const Fixed& copy);
		virtual ~Fixed();
		Fixed& operator=(const Fixed& copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
