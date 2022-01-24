#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap 
{
private:

public:
	ScavTrap( std::string name = "SC4V-TP" );
	~ScavTrap();
	void	attack( std::string const &target );
	void	guardGate();
};

#endif