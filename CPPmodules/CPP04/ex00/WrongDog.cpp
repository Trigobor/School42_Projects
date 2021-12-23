#include "WrongDog.hpp"

WrongDog::WrongDog(std::string Type) : WrongAnimal()
{
	this->type = Type;
	std::cout << "O hi " << this->type << std::endl;
};

WrongDog::~WrongDog()
{std::cout << "Rest in Pepsi, " << this->type << std::endl;};

void	WrongDog::makeSound() const
{std::cout << "WrongDog says: You're tearing me apart, Lisa!" << std::endl;};