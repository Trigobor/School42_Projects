#include "PhoneBook.hpp"

int		main()
{
	std::string command;
	ShittyPhoneBook book = ShittyPhoneBook();

	while (true)
	{

		std::getline(std::cin, command);
		if (command == "ADD")
			book.addNewContact();
		else if (command == "SEARCH")
		{
			std::cout << "|index     |first name|last name |nickname  |" << std::endl;
			book.searchContact();
			book.entireContact();
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "$%#@!" << std::endl;
	}
	return 0;
}