#include "FragTrap.hpp"



FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->attackDamage = 30;
	this->energyPoints = 100;
	std::cout << this->name << ": I am a sexy donosaur... ROARH!" << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << this->name << ": This is how it ends? NOOOAHAAHAAAH! *sigh* AAAAAAAAAAAAAAAA!" << std::endl;
};

void FragTrap::hightFiveGuys()
{
	if (this->hitPoints > 0)
		std::cout << this->name << ": Have Five! Give me Five! Secret handshake! Up-top! COME-ON! " << std::endl;
}
