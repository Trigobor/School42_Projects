#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string	name;
	int grade;
	int gexec;
	bool sign;
public:
	Form(std::string name = "none", int grade = 150, int gexec = 150);
	Form(Form &sample);
	Form	&operator=(Form &sample);
	~Form();
	int	getGrade();
	int getGexec();
	bool getSign();
	std::string getName();
	void setGrade(int i);
	void incGrade();
	void decGrade();
	void beSigned(Bureaucrat &sample);
	void setSign()
	{this->sign = true;};

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