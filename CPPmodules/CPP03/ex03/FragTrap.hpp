#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap 
{
private:

public:
	FragTrap( std::string name = "FR4G-TP");
	~FragTrap();
	void	hightFiveGuys();
};

#endif