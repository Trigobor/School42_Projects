#include "Form.hpp"

Form::Form(std::string name, int grade, int gexec) : name(name + " form"), grade(grade), gexec(gexec)
{
	this->sign = false;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	if (gexec > 150)
		throw GradeTooLowException();
	else if (gexec < 1)
		throw GradeTooHighException();
};

Form::~Form()
{};

Form::Form(Form &sample) : target(sample.target), name(sample.name), grade(sample.grade), gexec(sample.gexec), sign(sample.sign)
{};

Form	&Form::operator=(Form &sample)
{
	name = sample.name;
	grade = sample.grade;
	gexec = sample.gexec;
	sign = sample.sign;
	target = sample.target;
	return *this;
};

std::string Form::getName()
{return this->name;};

int Form::getGrade()
{return this->grade;};

int Form::getGexec()
{return this->gexec;};

void Form::setGrade(int i)
{
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
	else
		this->grade = i;
};

void Form::incGrade()
{
	if ((this->grade - 1) < 1)	
		throw GradeTooHighException();
	else
		this->grade--;
};

void Form::decGrade()
{
	if ((this->grade + 1) > 150)	
		throw GradeTooLowException();
	else
		this->grade++;
};

std::ostream& operator<<(std::ostream &stream, Form &sample)
{
	stream << (sample.getName() + ", form grade ") << sample.getGrade() << ", is signed(" << sample.getSign() << ") " << std::endl;
	return (stream);
};

void Form::beSigned(Bureaucrat &sample)
{
	if (sample.getGrade() > this->getGexec())
		throw GradeTooLowException();
	else
		this->sign = true;
};

bool Form::getSign()
{return this->sign;};

void Form::setTarget(std::string target)
{this->target = target;};

std::string Form::getTarget()
{return this->target;};

void Form::setGexec(int i)
{
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
	else
		this->gexec = i;
};

void Form::setName(std::string name)
{this->name = name;};