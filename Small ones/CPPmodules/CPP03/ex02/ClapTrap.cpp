#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)	:	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{std::cout << this->name << ": Hello minion!" << std::endl;};

ClapTrap::~ClapTrap()
{std::cout << this->name << ": I will die full of happiness!" << std::endl;};

void ClapTrap::attack( std::string const &target )
{
	if (this->hitPoints <= 0)
		return ;
	std::cout << this->name << ": Go on, minion, attack this " << target + ' ' << "with " << this->attackDamage << " attack damage!" << std::endl;
};

void ClapTrap::takeDamage( unsigned int amount )
{
	if (this->hitPoints <= 0)
		return ;
	std::cout << this->name << ": PROTECT ME!" << std::endl;
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << this->name << ": I'm dying!" << std::endl;
	}
	else
		this->hitPoints -= amount;
};

void ClapTrap::beRepaired( unsigned int amount )
{
	if (this->hitPoints <= 0)
		return ;
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << ": I'm wasted!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << this->name << ": Check me out! *beatbox sounds*\n*making wave* I'm dancing! I'm dancing! *beatbox sounds*" << std::endl;
};
