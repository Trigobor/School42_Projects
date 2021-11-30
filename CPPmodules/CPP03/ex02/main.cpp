#include "FragTrap.hpp"

int main()
{
	FragTrap claptrap("FR4G-TP");

	claptrap.hightFiveGuys();
	claptrap.attack("Psycho");
	claptrap.takeDamage(5);
	claptrap.beRepaired(1);
	claptrap.takeDamage(100);
	for (int i = 20; i > 0; i--)
		claptrap.beRepaired(1);
}