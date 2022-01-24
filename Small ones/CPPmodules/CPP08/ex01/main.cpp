#include "span.hpp"

int main()
{
	std::cout << "Test 0" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "min span test 0 " << sp.shortestSpan() << std::endl;
	std::cout << "max span test 0 " << sp.longestSpan() << std::endl;
	std::cout << "Test 1" << std::endl;
	Span s = Span(1);
		s.addNumber(3);
	try
	{
		s.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Test 2" << std::endl;
	try
	{
		std::cout << s.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Test 3" << std::endl;
	Span d = Span(10000);
	d.addNumber(1);
	d.addNumber(1);
	d.fillSpan();
	std::cout << "min span test 3 " <<  d.shortestSpan() << std::endl;
	std::cout << "max span test 3 " <<  d.longestSpan() << std::endl;
}
