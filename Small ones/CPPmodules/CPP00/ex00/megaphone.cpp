#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	int	word = 1;
	int	letter;
	while (word != ac)
	{
		letter = 0;
		while (av[word][letter])
		{
			if (std::islower(av[word][letter]))
				std::cout << (char)std::toupper(av[word][letter++]);
			else
				std::cout << av[word][letter++];
		}
		word++;
	}
	std::cout << std::endl;
	return 0;
}