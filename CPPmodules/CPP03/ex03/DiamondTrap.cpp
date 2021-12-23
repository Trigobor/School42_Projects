#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name + " Telecommunications Bot")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

	std::cout << this->name << ": Greetings! I am a " << ClapTrap::name << ", but you can just call me Veronica!" << std::endl;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << this->name << ": Not again!" << std::endl;
};

void DiamondTrap::attack(const std::string &target) 
{
	ScavTrap::attack(target);
};

void DiamondTrap::whoAmI() 
{
	if (this->hitPoints > 0)
		std::cout << this->name << ": I am a " << ClapTrap::name << ", but you can just call me " << this->name << "!" << std::endl;
}
