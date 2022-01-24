#include "PhoneBook.hpp"

void	ShittyPhoneBook::addNewContact()
{
	static int	i = 0;
	
	std::string	foreName;
	std::string	lastName;
	std::string	nickName;
	std::string	phNumber;
	std::string	darkScrt;

	std::cout << "First name?" << std::endl;
	std::getline(std::cin, foreName);
	std::cout << "Last name?" << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Nick name?" << std::endl;
	std::getline(std::cin, nickName);
	std::cout << "Phone number?" << std::endl;
	std::getline(std::cin, phNumber);
	std::cout << "Darkest secret?" << std::endl;
	std::getline(std::cin, darkScrt);

	this->contacts[i].rewriteContact(foreName, lastName, nickName, phNumber, darkScrt, i);
    i++;
	if (i == 8)
		i = 0;
}

void	ShittyPhoneBook::searchContact()
{
	int i = 0;

	while (i < 8)
	{
		if (this->contacts[i].contactsNumber() != -1)
			this->contacts[i].retContactInfo();
		i++;
	}
}

int		rule(const char *str)
{
	int i = 0;
	while (str[i])
	{
		if (std::isdigit(str[i]) == 0)
			return -1;
		i++;
	}
	return 1;
}

void	ShittyPhoneBook::entireContact()
{
	int i = 0;
	std::string	input;

	std::getline(std::cin, input);
	i = std::atoi(input.data());
	if (i > 7 || i < 0 || this->contacts[i].contactsNumber() == -1 || rule(input.data()) == -1)
	{
		std::cout << "$%#@!" << std::endl;
		return ;
	}
	this->contacts[i].retFullContact();
}

ShittyPhoneBook::ShittyPhoneBook()
{
    int i = 0;
    while (i < 8)
    {
        this->contacts[i] = ShittyContact();
        i++;
    }
}