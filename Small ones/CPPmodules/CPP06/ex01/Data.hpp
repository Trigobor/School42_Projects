#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data
{
	std::string	str;
	int			num;
};

uint *serialize(Data *ptr);
Data *deserialize(uint *raw);

#endif