#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal(std::string Type = "WrongAnimal");
	WrongAnimal(WrongAnimal &sample);
	~WrongAnimal();
	std::string	getType() const;
	WrongAnimal	&operator=(WrongAnimal &sample);

	void	makeSound() const;
};

#endif