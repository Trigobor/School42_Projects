#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(std::string Type = "Dog");
	Dog(const Dog &sample);
	virtual ~Dog();
    virtual void	makeSound() const;
    Dog& operator= (const Dog &sample);
	void	goodIdea(int i);
private:
	Brain*	brain;
};

#endif