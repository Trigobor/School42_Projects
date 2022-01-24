#include "Identify.hpp"

int main()
{
	Base *parr = generate();
	std::cout << "pointer says: ";
	identify(parr);
	std::cout << "reference says: ";
	identify(*parr);
};