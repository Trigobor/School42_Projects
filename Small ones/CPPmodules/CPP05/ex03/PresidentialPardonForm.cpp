#include <fstream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 25, 5)
{this->setTarget(target);};

PresidentialPardonForm::~PresidentialPardonForm()
{};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &sample) : Form("PresidentialPardon", 25, 5)
{
	this->setDefSign();
	this->setTarget(sample.getTarget());
};

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &sample)
{
	this->setDefSign();
	this->setGrade(25);
	this->setGexec(5);
	this->setTarget(sample.getTarget());
	this->setName("PresidentialPardon form");
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &executor)
{
	if (!this->getSign())
		throw NotSignException();
	else if (this->getGexec() < executor.getGrade())
		throw GradeTooLowException();
	else
		std::cout << "Tells us that " + this->getTarget() + " has been pardoned by Zafod Beeblebrox." << std::endl;
};