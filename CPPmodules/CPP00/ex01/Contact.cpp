#include "Contact.hpp"

void	ShittyContact::retFullContact()
{
	std::cout << "Index is: " << this->strIndex << std::endl;
	std::cout << "First name is: " << this->foreName << std::endl;
	std::cout << "Last name is: " << this->lastName << std::endl;
	std::cout << "Nickname is: " << this->nickName << std::endl;
	std::cout << "Phone number is: " << this->phNumber << std::endl;
	std::cout << "Dark secret is: " << this->darkScrt << std::endl;
}

int		ShittyContact::contactsNumber()
{
	return (this->number);
}

void	ShittyContact::retContactInfo()
{
	int i = 0;

	std::cout << "|" << this->strIndex << "         " << "|";
	if (this->foreName.size() > 10)
		std::cout << this->foreName.substr(0, 9) << "." << "|";
	else
	{
		std::cout << this->foreName;
		i = 10 - this->foreName.size();
		while (i--)
			std::cout << " ";
		std::cout << "|";
	}
	if (this->lastName.size() > 10)
		std::cout << this->lastName.substr(0, 9) << "." << "|";
	else
	{
		std::cout << this->lastName;
		i = 10 - this->lastName.size();
		while (i--)
			std::cout << " ";
		std::cout << "|";
	}
	if (this->nickName.size() > 10)
		std::cout << this->nickName.substr(0, 9) << "." << "|";
	else
	{
		std::cout << this->nickName;
		i = 10 - this->nickName.size();
		while (i--)
			std::cout << " ";
		std::cout << "|";
	}
	std::cout << std::endl;
}

void	ShittyContact::rewriteContact(std::string foreName, std::string lastName, std::string nickName,
        std::string phNumber, std::string darkScrt, int i)
{
	this->number = i;
	if (foreName.size() != 0)
		this->foreName = foreName;
	if (lastName.size() != 0)
		this->lastName = lastName;
	if (nickName.size() != 0)
		this->nickName = nickName;
	if (phNumber.size() != 0)
		this->phNumber = phNumber;
	if (darkScrt.size() != 0)
		this->darkScrt = darkScrt;
	this->strIndex = std::to_string(i);
}

ShittyContact::ShittyContact()
{
	this->number = -1;
	this->foreName = "\0";
	this->lastName = "\0";
	this->nickName = "\0";
	this->phNumber = "\0";
	this->darkScrt = "\0";
}