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
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;

//операторы
	Fixed &operator	= (const Fixed &obj);
	bool operator == (const Fixed &obj) const;
	bool operator < (const Fixed &obj) const;
	bool operator <= (const Fixed &obj) const;
	bool operator > (const Fixed &obj) const;
	bool operator >= (const Fixed &obj) const;
	bool operator != (const Fixed &obj) const;
	Fixed operator + (const Fixed &obj) const;
	Fixed operator - (const Fixed &obj) const;
	Fixed operator * (const Fixed &obj) const;
	Fixed operator / (const Fixed &obj) const;
	Fixed &operator ++ ();
	Fixed operator ++ (int);
	Fixed &operator -- ();
	Fixed operator -- (int);

//минмакс
	static Fixed &min(Fixed &obj1, Fixed &obj2);//
	static Fixed &max(Fixed &obj1, Fixed &obj2);//
	static const Fixed &min(Fixed const &obj1, Fixed const &obj2);//
	static const Fixed &max(Fixed const &obj1, Fixed const &obj2);//
};

std::ostream &operator << (std::ostream &out, const Fixed &obj);

#endif