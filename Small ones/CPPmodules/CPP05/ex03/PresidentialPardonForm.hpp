#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string target = "Guess who?");
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm &sample);
	PresidentialPardonForm	&operator=(PresidentialPardonForm &sample);
	virtual void execute(Bureaucrat &executor);
	class NotSignException : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("is not signed");}
	};
};
