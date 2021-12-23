#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string Type) : type(Type)
{std::cout << "O hi " << this->type << std::endl;};

WrongAnimal::WrongAnimal(WrongAnimal &sample) : type(sample.getType())
{std::cout << "O hi " << this->type << std::endl;};

WrongAnimal::~WrongAnimal()
{std::cout << "Rest in Pepsi, " << this->type << std::endl;};

std::string WrongAnimal::getType() const
{return(this->type);};

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &sample)
{
	this->type = sample.getType();
	return (*this);
};

void	WrongAnimal::makeSound() const
{std::cout << "I have an announcement to make: Cheep cheep cheep cheep cheeeeeeeep" << std::endl;};