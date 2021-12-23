#include "Animal.hpp"

Animal::Animal(std::string Type) : type(Type)
{std::cout << "O hi " << this->type << std::endl;};

Animal::Animal(Animal &sample) : type(sample.getType())
{std::cout << "O hi " << this->type << std::endl;};

Animal::~Animal()
{std::cout << "Rest in Pepsi, " << this->type << std::endl;};

std::string Animal::getType() const
{return(this->type);};

Animal	&Animal::operator=(Animal &sample)
{
	this->type = sample.getType();
	return (*this);
};

void	Animal::makeSound() const
{std::cout << "I have an announcement to make: Cheep cheep cheep cheep cheeeeeeeep" << std::endl;};