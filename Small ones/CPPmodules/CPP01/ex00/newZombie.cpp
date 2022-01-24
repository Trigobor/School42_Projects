#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* heappie = new Zombie(name);
	return heappie;
}
