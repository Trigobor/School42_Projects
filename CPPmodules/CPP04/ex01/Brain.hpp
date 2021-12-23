#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
public:
	Brain();
	Brain(Brain &sample);
	~Brain();
	std::string idea[100];
};

#endif