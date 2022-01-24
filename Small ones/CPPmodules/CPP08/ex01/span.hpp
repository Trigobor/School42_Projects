#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int maxnumints;
	std::vector<int> number;
public:
	~Span();
	Span(unsigned int N);
	void addNumber(int i);
	void fillSpan();
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class Err : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("There is an error");}
	};
};

#endif