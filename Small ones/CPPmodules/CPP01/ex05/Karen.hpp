#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen
{
	private:
		void warning( void );
		void debug( void );
		void error( void );
		void info( void );
		void eeee( void );
	public:
		Karen();
		void complain( std::string level );
};

#endif