#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat("Mark");
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	const WrongAnimal *atem = new WrongAnimal();
	const WrongAnimal *notadog = new WrongDog();
	std::cout << "(WrongAnimal) ";
	atem->makeSound();
	std::cout << "(WrongDog) ";
	notadog->makeSound();
	delete atem;
	delete notadog;
}