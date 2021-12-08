#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	printtmplt(T b)
{std::cout << "item is: " << b << std::endl;};

template<typename T>
void	iter(T *a, int len, void (*f)(T b))
{
	for (int i = 0; i < len; i++)
		f(a[i]);
};

#endif