#include "Brain.hpp"

Brain::Brain()
{
	std::string one[] = {"I want ", "I do not want ", "I demand ", "I would love ", "I wish "};
	std::string two[] = {"you ", "crab ", "tomato ", "coffee ", "my own happiness "};
	std::string three[] = {"as a burrito", "to became a superhero", "to trow it on your window", "to make a pet of it", "to die"};
	std::string idea;
	int i;
	int ii;
	int iii;
	srand(time(0));

	for (int a = 0; a != 100; a++)
	{
		i = rand() % 5;
		ii = rand() % 5;
		iii = rand() % 5;
		this->idea[a] = "Idea: " + one[i] + two[ii] + three[iii];
	}

};

Brain::Brain(Brain &sample)
{
	for (int i = 0; i < 100; i++)
		this->idea[i] = sample.idea[i];
};

Brain::~Brain()
{std::cout << "Brain is falling apart!" << std::endl;};
