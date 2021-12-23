#include <fstream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest", 72, 45)
{this->setTarget(target);};

RobotomyRequestForm::~RobotomyRequestForm()
{};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &sample) : Form("RobotomyRequest", 72, 45)
{
	this->setDefSign();
	this->setTarget(sample.getTarget());
};

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &sample)
{
	this->setDefSign();
	this->setGrade(72);
	this->setGexec(45);
	this->setTarget(sample.getTarget());
	this->setName("RobotomyRequest form");
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &executor)
{
	if (!this->getSign())
		throw NotSignException();
	else if (this->getGexec() < executor.getGrade())
		throw GradeTooLowException();
	else
	{
		int i;
		srand(time(0));
		i = rand();
		if (i % 2)
			std::cout << "Makes some drilling noises, and tell us that " + this->getTarget() + "  has been robotomized successfully" << std::endl;
		else
			std::cout << "Makes some drilling noises, and tell us that " + this->getTarget() + "  has been robotomized unsuccessfully" << std::endl;
	}
};