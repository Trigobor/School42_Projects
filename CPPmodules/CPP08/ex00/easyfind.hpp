#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class Exception : public std::exception{
	const char* what(void) const throw ()
	{return "404 Not found";};
};

template <typename T>
typename T::iterator easyfind(T where, int what)
{
	typename T::iterator rez;

	rez = std::find(where.begin(), where.end(), what);
	if (rez == where.end())
		throw Exception();
	else
		return rez;
};

#endif