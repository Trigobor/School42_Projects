#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string target = "Somebody");
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm &sample);
	RobotomyRequestForm	&operator=(RobotomyRequestForm &sample);
	virtual void execute(Bureaucrat &executor);
	class NotSignException : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("is not signed");}
	};
};
