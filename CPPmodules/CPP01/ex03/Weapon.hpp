#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		std::string const	&getType() const;
		void				setType(std::string str);
	private:
		std::string	type;
};

#endif