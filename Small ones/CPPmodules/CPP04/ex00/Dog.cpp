#include "Dog.hpp"

Dog::Dog(std::string Type) : Animal()
{
	this->type = Type;
	std::cout << "O hi " << this->type << std::endl;
};

Dog::~Dog()
{std::cout << "Rest in Pepsi, " << this->type << std::endl;}

void	Dog::makeSound() const
{std::cout << "Dog says: You're tearing me apart, Lisa!" << std::endl;};
