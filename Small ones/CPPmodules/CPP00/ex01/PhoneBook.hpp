#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class ShittyPhoneBook
{
	public:
		ShittyPhoneBook();
		void	addNewContact();
		void	searchContact();
		void	entireContact();
		ShittyContact	contacts[8];
	private:
};
#endif