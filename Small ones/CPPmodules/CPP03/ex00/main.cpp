#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Psycho");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	claptrap.takeDamage(10);
	for (int i = 10; i > 0; i--)
		claptrap.beRepaired(1);
}