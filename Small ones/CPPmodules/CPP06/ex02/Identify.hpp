#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Kids.hpp"

Base *generate(void)
{
	Base *rez;
	srand(time(0));
	int r = rand() % 3;
	switch(r)
	{
		case(0):
		{
			rez = new A;
			std::cout << "this is A" << std::endl;
			break;
		}
		case(1):
		{
			rez = new B;
			std::cout << "this is B" << std::endl;
			break;
		}
		case(2):
		{
			std::cout << "this is C" << std::endl;
			rez = new C;
			break;
		}
	}
	return rez;
};

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "this is A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "this is B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "this is C" << std::endl;
};
void identify(Base& p)
{identify(&p);};

#endif