#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int	mantissa;
		static const int exponant = 8;
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed& copy);
		~Fixed();

		Fixed& operator=(const Fixed& fixed);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		friend Fixed operator+(Fixed& f1, const Fixed f2);
		friend Fixed operator-(Fixed& f1, const Fixed f2);
		friend Fixed operator*(Fixed& f1, const Fixed f2);
		friend Fixed operator/(Fixed& f1, const Fixed f2);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& min(Fixed& f1, Fixed& f2);
		static Fixed& max(Fixed f1, Fixed& f2);
		static Fixed& max(const Fixed& f1, const Fixed& f2);
};

#endif
