#include "Data.hpp"

uint *serialize(Data *ptr)
{
	int len;
	int c;
	int i;
	int l;

	i = sizeof(int);
	c = sizeof(char);
	l = (ptr->str.length());
	len = (l * c) + (i * 2);
	char *rez = new char[len];
	*reinterpret_cast<uint*>(rez) = l;
	for (int j = 0; j < l; j++)
		rez[4 + j] = ptr->str[j];
	*reinterpret_cast<uint*>(rez + (4 + l)) = ptr->num;
	return (uint*)(rez);
};

//char = 8 бит = 1
//int = 32 бит = 4

Data *deserialize(uint *raw)
{
	Data *rez = new Data;
	char *r = (char*)raw;
	int l; 
	l = *reinterpret_cast<int*>(static_cast<char*>(r));
	rez->str = std::string(static_cast<char*>(r) + 4, l);
	rez->num = *reinterpret_cast<int*>(static_cast<char*>(r) + (4 + l));
	return rez;
};