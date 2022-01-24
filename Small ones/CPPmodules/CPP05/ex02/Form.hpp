#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string target;
	std::string	name;
	int grade;
	int gexec;
	bool sign;
public:
	Form(std::string name = "none", int grade = 150, int gexec = 150);
	Form(Form &sample);
	Form	&operator=(Form &sample);
	virtual ~Form();
	int	getGrade();
	int getGexec();
	bool getSign();
	std::string getTarget();
	std::string getName();
	void setGrade(int i);
	void setTarget(std::string target);
	void incGrade();
	void decGrade();
	void beSigned(Bureaucrat &sample);
	void setGexec(int i);
	void setName(std::string name);
	void setSign()
	{this->sign = true;};
	void setDefSign()
	{this->sign = false;};
	virtual void execute(Bureaucrat &executor) = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("Grade is too hight");}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("Grade is too low");}
	};
};
std::ostream& operator<<(std::ostream &stream, Form &sample);

#endif