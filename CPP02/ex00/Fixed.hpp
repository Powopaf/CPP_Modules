#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int fix_num;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed& operator=(const Fixed& copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
