#include "ScavTrap.hpp"

int main()
{
	ScavTrap claptrap("SC4V-TP");

	claptrap.guardGate();
	claptrap.attack("Psycho");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	claptrap.takeDamage(100);
	for (int i = 20; i > 0; i--)
		claptrap.beRepaired(1);
}