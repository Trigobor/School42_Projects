#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					fixed_point_value;
	static const int	num_of_fract_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &obj);
	Fixed &operator = (const Fixed &obj);
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream &operator << (std::ostream &out, const Fixed &obj);

#endif