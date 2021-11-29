#include "Fixed.hpp"

Fixed::Fixed()	:	fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &obj)	:	fixed_point_value(obj.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
};

//work
Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = val << 8;
}

//work
Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = (int)roundf(val * (1 << 8));
}

Fixed &Fixed::operator = (const Fixed &obj)
{
	this->fixed_point_value = obj.getRawBits();
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
};

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

//work
int		Fixed::toInt() const
{
	return (this->fixed_point_value >> 8);
}

//work
float	Fixed::toFloat() const
{
	return (float)((float)this->fixed_point_value / (float)(1 << 8));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

std::ostream &operator << (std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}