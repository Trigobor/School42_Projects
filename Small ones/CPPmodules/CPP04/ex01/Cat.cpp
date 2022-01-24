#include "Cat.hpp"

Cat::Cat(std::string Type) : Animal()
{
	this->type = Type;
	this->brain = new Brain();
	std::cout << "O hi " << this->type << std::endl;
};

Cat::~Cat()
{
	std::cout << "Rest in Pepsi, " << this->type << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat::Cat(const Cat &sample) : Animal()
{
	std::cout << "Copycat" << std::endl;
	this->type = sample.getType();
	this->brain = new Brain(*sample.brain);
};

void	Cat::goodIdea(int i)
{
	std::cout << this->brain->idea[i] << std::endl;
}

Cat& Cat::operator= (const Cat &sample)
{
	std::cout << "Copycat" << std::endl;
	if (this->brain)
	{
		std::cout << this->getType() << ": I'm starting to think like a " << sample.getType() << ", obviously, my ";
		delete this->brain;
	}
	this->type = sample.getType();
	this->brain = new Brain(*sample.brain);
	return (*this);
};

void	Cat::makeSound() const
{std::cout << "Cat says: I did not hit her! It's not true! It's bullshit! I did not hit her! I did nooot!" << std::endl;};