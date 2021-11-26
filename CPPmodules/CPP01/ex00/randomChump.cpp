#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	starck = Zombie(name);
	starck.announce();
}
