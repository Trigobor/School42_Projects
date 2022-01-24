#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>(){};
	~MutantStack(){};
	iterator begin()
	{};
	iterator end()
	{return this->c.end();};
	iterator peek(int depth)
	{return (this->c.begin() + depth);};
};

#endif
