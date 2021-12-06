#include "Form.hpp"

class StrawberryForm : public Form
{
public:
	StrawberryForm(std::string target = "home");
	~StrawberryForm();
	StrawberryForm(StrawberryForm &sample);
	StrawberryForm	&operator=(StrawberryForm &sample);
	virtual void execute(Bureaucrat &executor);
	class NotSignException : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("is not signed");}
	};
};
