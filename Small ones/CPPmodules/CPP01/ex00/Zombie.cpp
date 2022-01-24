#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
	this->name = '<' + n + '>';
}

Zombie::~Zombie()
{
	std::cout << "Rest in peace, " << this->name << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}