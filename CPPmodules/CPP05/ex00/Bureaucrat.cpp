#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
};

Bureaucrat::~Bureaucrat()
{};

Bureaucrat::Bureaucrat(Bureaucrat &sample) : name(sample.name), grade(sample.grade)
{};

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &sample)
{
	name = sample.name;
	grade = sample.grade;
	return *this;
};

std::string Bureaucrat::getName()
{return this->name;};

int Bureaucrat::getGrade()
{return this->grade;};

void Bureaucrat::setGrade(int i)
{
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
	else
		this->grade = i;
};

void Bureaucrat::incGrade()
{
	if ((this->grade - 1) < 1)	
		throw GradeTooHighException();
	else
		this->grade--;
};

void Bureaucrat::decGrade()
{
	if ((this->grade + 1) > 150)	
		throw GradeTooLowException();
	else
		this->grade++;
};

std::ostream& operator<<( std::ostream &stream, Bureaucrat &sample)
{
	stream << (sample.getName() + ", bureaucrat grade ");
	stream << sample.getGrade();
	return (stream);
}
