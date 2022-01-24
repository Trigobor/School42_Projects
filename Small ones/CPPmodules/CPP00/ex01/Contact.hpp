#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class ShittyContact
{
	public:
		ShittyContact();
		void	retFullContact();
		void	rewriteContact(std::string foreName, std::string lastName, std::string nickName,
        std::string phNumber, std::string darkScrt, int i);
		void	retContactInfo();
		int		contactsNumber();
	private:
		int	number;
		std::string	foreName;
		std::string	lastName;
		std::string	nickName;
		std::string	phNumber;
		std::string	darkScrt;
		std::string	strIndex;
};
#endif