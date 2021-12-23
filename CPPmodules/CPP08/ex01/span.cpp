#include "span.hpp"
#include <limits>

Span::Span(unsigned int N) : maxnumints(N)
{};

Span::~Span()
{};

void Span::addNumber(int i)
{
	if (number.size() >= maxnumints)
		throw Err();
	else
		number.push_back(i);
};

unsigned int Span::longestSpan()
{
	if (number.size() <= 1)
		throw Err();
	return static_cast<unsigned int>((*std::max_element(number.begin(), number.end())) - \
	(*std::min_element(number.begin(), number.end())));
};

unsigned int Span::shortestSpan()
{
	if (number.size() <= 1)
		throw Err();
	unsigned int rez = std::numeric_limits<unsigned int>::max();
	std::vector<int> sorted = number;
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::iterator curr = sorted.begin() + 1;curr != sorted.end();curr++)
	{
		if (static_cast<unsigned int>(*curr - *(curr - 1)) < rez)
			rez = static_cast<unsigned int>(*curr - *(curr - 1));
	}
	if (static_cast<unsigned int>(*sorted.end() - *(sorted.end() - 1)) < rez)
		rez = static_cast<unsigned int>(*sorted.end() - *(sorted.end() - 1));
	return rez;
};

void Span::fillSpan()
{
	unsigned int iterations = maxnumints - static_cast<unsigned int>(number.size());
	srand(time(0));
	for (unsigned int i = 0; i < iterations; i++)
		addNumber(rand() % 100);
};
