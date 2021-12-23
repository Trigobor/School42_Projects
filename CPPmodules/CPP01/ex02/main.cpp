#include <iostream>

#define TEST 0

int	main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string	&stringREF = str;
	std::string	stringDUP = str;

	std::cout << "address in memory of the string: " << &str << std::endl;
	std::cout << "address of the string by using stringPTR: " << stringPTR << std::endl;
	std::cout << "address of the string by using stringREF: " << &stringREF << std::endl;
	if (TEST)
	{
		std::cout << "address of the string by using stringDUP: " << &stringDUP << std::endl;
		std::cout << "string by using str: " << str << std::endl;
	}

	std::cout << "string by using stringPTR: " << *stringPTR << std::endl;
	std::cout << "string by using stringREF: " << stringREF << std::endl;

	return 0;
}