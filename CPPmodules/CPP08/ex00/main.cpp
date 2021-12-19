#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::cout << *easyfind(a, 3) << std::endl;
	try
	{
		std::cout << *easyfind(a, 4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};