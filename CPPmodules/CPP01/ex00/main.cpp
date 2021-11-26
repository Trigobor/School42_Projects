#include "Zombie.hpp"

int main(void)
{
	Zombie *heappie;

	heappie = newZombie("Heappie");
	heappie->announce();
	delete heappie;
	randomChump("Starck");
	return 0;
}