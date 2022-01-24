#include "Karen.hpp"

int main(int ac, char **av)
{
	Karen kar = Karen();
	
	if (ac != 2)
	{
		std::cout << "*passively-aggressively annoys everyone*" << std::endl;
		return 1;
	}
	kar.complain(av[1]);
	return 0;
}
