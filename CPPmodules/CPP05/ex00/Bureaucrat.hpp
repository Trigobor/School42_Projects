#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	std::string	name;
	int grade;
public:
	Bureaucrat(std::string name = "none", int grade = 150);
	Bureaucrat(Bureaucrat &sample);
	Bureaucrat	&operator=(Bureaucrat &sample);
	~Bureaucrat();
	int	getGrade();
	std::string getName();
	void setGrade(int i);
	void incGrade();
	void decGrade();

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
std::ostream& operator<<( std::ostream &stream, Bureaucrat &sample );

#endif