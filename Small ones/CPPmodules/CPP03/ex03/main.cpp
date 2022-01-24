#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap claptrap("VR-0N1CA");

	claptrap.hightFiveGuys();
	claptrap.guardGate();
	claptrap.whoAmI();
	claptrap.attack("Psycho");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	claptrap.takeDamage(100);
	for (int i = 20; i > 0; i--)
		claptrap.beRepaired(1);
}