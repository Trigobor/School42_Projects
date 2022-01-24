#include "Zombie.hpp"

int main(void)
{
	Zombie *heappies;
	int i = 0;

	std::cout << "din" << std::endl;
	heappies = zombieHorde(10, "August");
	std::cout << "done" << std::endl;
	while (i < 10)
	{
		heappies[i].announce();
		i++;
	}
	delete [] heappies;
	return 0;
}