#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(std::string Type = "Animal");
	Animal(Animal &sample);
	virtual ~Animal();
	std::string	getType() const;
	Animal	&operator=(Animal &sample);

	virtual void	makeSound() const = 0;
};

#endif