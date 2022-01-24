#include "Intern.hpp"

Intern::Intern()
{};

Intern::~Intern()
{};

//Intern::Intern(Intern &sample)
//{*this = sample;};

//Intern &Intern::operator=(Intern &sample)
//{
//	(void)sample;
//	std::cout << "We are already the same" << std::endl;
//};

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string array[] = {	"Strawberry",
							"Robotomy request",
							"Presidential pardon"};
	int lvl = -1;
	for (int i = 0; i < 3 && lvl == -1; i++)
		if (name == array[i])
			lvl = i;
	switch (lvl)
	{
		case(0):
		{
			std::cout << "Intern: StrawberryForm is ready" << std::endl;
			Form *rez = new StrawberryForm(target);
			return (rez);
		}
		case(1):
		{
			std::cout << "Intern: RobotomyRequestForm is ready" << std::endl;
			Form *rez = new RobotomyRequestForm(target);
			return (rez);
		}
		case(2):
		{
			std::cout << "Intern: PresidentialPardonForm is ready" << std::endl;
			Form *rez = new PresidentialPardonForm(target);
			return (rez);
		}
		default:
			std::cout << "Intern: *panics*" << std::endl;
	}
	return nullptr;
};