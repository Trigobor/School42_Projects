#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	std::string root[] = {"Ol", "Lun", "Hjort", "Oks", "Aist", "Hund", "Ulf", "Bjorn", "Svein", "Orn"};
	std::string suff[] = {"", "rask", "lur", "", "flak", "dyrt", "rik", "", "snill", ""};
	std::string fullname;
	int i = 0;
	int r;
	int s;
	srand(time(0));

	while (i < N)
	{
		r = rand() % 10;
		s = rand() % 10;
		fullname = name + " " + root[r] + suff[s];
		if (r % 2)
			fullname = fullname + "dotter";
		else
			fullname = fullname + "sen";
		horde[i].naming(fullname);
		i++;
	}
	return horde;
}