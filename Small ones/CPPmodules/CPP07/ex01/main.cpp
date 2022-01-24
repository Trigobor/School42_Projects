#include "iter.hpp"

int main()
{
	int i[] = {1, 2, 3, 4, 5};
	char c[] = {'a', 'b', 'c', 'd', 'e'};
	iter(i, 5, printtmplt);
	std::cout << "\n";
	iter(c, 5, printtmplt);
};