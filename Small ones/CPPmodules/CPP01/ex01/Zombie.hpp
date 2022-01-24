#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		void	naming(std::string n);
		void	announce(void);
		Zombie(std::string n);
		~Zombie();
		Zombie();
	private:
		std::string name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif