#include "Data.hpp"

int main()
{
	Data d;
	Data *m;
	uint *i;
	d.str = "le lyol, keke, le chebureke";
	d.num = 4;
	i = serialize(&d);
	m = deserialize(i);
	std::cout << "str is: " << m->str << "\nint is: " << m->num << std::endl;
	delete m;
	delete i;
};