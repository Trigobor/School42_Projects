#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(std::string Type = "Cat");
	Cat(const Cat &sample);
	virtual ~Cat();
    virtual void	makeSound() const;
    Cat& operator= (const Cat &sample);
	void	goodIdea(int i);
private:
	Brain*	brain;
};

#endif