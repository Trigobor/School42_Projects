#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog(std::string Type = "WrongDog");
	~WrongDog();
    void	makeSound() const;
};

#endif