#include "Fixed.hpp"

Fixed::Fixed()	:	fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &obj)	:	fixed_point_value(obj.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
};

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
	fixed_point_value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};