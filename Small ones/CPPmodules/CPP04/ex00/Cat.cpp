#include "Cat.hpp"

Cat::Cat(std::string Type) : Animal()
{
	this->type = Type;
	std::cout << "O hi " << this->type << std::endl;
};

Cat::~Cat()
{std::cout << "Rest in Pepsi, " << this->type << std::endl;}

void	Cat::makeSound() const
{std::cout << "Cat says: I did not hit her! It's not true! It's bullshit! I did not hit her! I did nooot!" << std::endl;};