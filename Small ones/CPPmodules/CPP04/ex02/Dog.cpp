#include "Dog.hpp"

Dog::Dog(std::string Type) : Animal()
{
	this->type = Type;
	this->brain = new Brain();
	std::cout << "O hi " << this->type << std::endl;
};

Dog::~Dog()
{
	std::cout << "Rest in Pepsi, " << this->type << std::endl;
	if (this->brain)
		delete this->brain;
}

Dog::Dog(const Dog &sample) : Animal()
{
	std::cout << "Copydog" << std::endl;
	this->type = sample.getType();
	this->brain = new Brain(*sample.brain);
};

void	Dog::goodIdea(int i)
{
	std::cout << this->brain->idea[i] << std::endl;
}

Dog& Dog::operator= (const Dog &sample)
{
	std::cout << "Copydog" << std::endl;
	this->type = sample.getType();
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*sample.brain);
	return (*this);
};

void	Dog::makeSound() const
{std::cout << "Dog says: You're tearing me apart, Lisa!" << std::endl;};
