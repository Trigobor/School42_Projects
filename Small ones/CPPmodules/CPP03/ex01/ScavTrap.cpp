#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->attackDamage = 50;
	this->energyPoints = 20;
	std::cout << this->name << ": Halt, moon citizen!" << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << this->name << ": I do not regret anything!" << std::endl;
};

void ScavTrap::attack( std::string const &target )
{
	if (this->hitPoints <= 0)
		return ;
	std::cout << this->name << ": I will attack this " << target + ' ' << "with my " << this->attackDamage << " attack damage! FOR THE REDBELLY!" << std::endl;
};

void ScavTrap::guardGate()
{
	if (this->hitPoints > 0)
		std::cout << this->name << ": Guarding gates is FUN! I shall wait here, a noble-yet-dangerous robot, alone, mysterious, desprate to be loved..." << std::endl;
}