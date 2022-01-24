#include "Form.hpp"
#include "StrawberryForm.hpp"
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp" 

class Intern
{
public:
	Intern();
	~Intern();
//	Intern(Intern &sample);
//	Intern &operator=(Intern &sample);
	Form* makeForm(std::string name, std::string target);
};