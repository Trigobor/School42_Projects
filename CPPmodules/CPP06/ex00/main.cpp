#include "Convertion.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string arg(av[1]);
		try
		{
			Convertion lol = Convertion(arg);
			std::cout << lol;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout << "Invalid num of arguments" << std::endl;
}