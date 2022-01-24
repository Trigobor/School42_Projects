#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(std::string Type = "Doggy");
	virtual ~Dog();
    virtual void	makeSound() const;
};

#endif