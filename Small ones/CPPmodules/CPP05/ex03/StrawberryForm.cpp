#include "StrawberryForm.hpp"
#include <fstream>

StrawberryForm::StrawberryForm(std::string target) : Form("Strawberry", 145, 137)
{this->setTarget(target);};

StrawberryForm::~StrawberryForm()
{};

StrawberryForm::StrawberryForm(StrawberryForm &sample) : Form("Strawberry", 145, 137)
{
	this->setDefSign();
	this->setTarget(sample.getTarget());
};

StrawberryForm	&StrawberryForm::operator=(StrawberryForm &sample)
{
	this->setDefSign();
	this->setGrade(145);
	this->setGexec(137);
	this->setTarget(sample.getTarget());
	this->setName("Strawberry form");
	return (*this);
}

void StrawberryForm::execute(Bureaucrat &executor)
{
	if (!this->getSign())
		throw NotSignException();
	else if (this->getGexec() < executor.getGrade())
		throw GradeTooLowException();
	else
	{
		std::ofstream file;
		file.open(this->getTarget() + "_shrubbery" );
    	if (!file)
	        std::cout << "Failed to open";
		else
		{
			std::cout << "Bureaucrat named '" + executor.getName() + "' executes '" + this->getName() + "'" << std::endl;
			file << "         . . .\n"
					"       .        .  .     ..    .\n"
					"    .                 .         .  .\n"
					"                    .\n"
					"                   .                ..\n"
					"   .          .            .              .\n"
					"   .            '.,        .               .\n"
					"   .              'b      *\n"
					"    .              '$    #.                ..\n"
					"   .    .           $:   #:               .\n"
					" ..      .  ..      *#  @):        .   . .\n"
					"              .     :@,@):   ,.**:'   .\n"
					"  .      .,         :@@*: ..**'      .   .\n"
					"           '#o.    .:(@'.@*''  .\n"
					"   .  .       'bq,..:,@@*'   ,*      .  .\n"
					"              ,p$q8,:@)'  .p*'      .\n"
					"       .     '  . '@@Pp@@*'    .  .\n"
					"        .  . ..    Y7'.'     .  .\n"
					"                  :@):.\n"
					"                 .:@:'.\n"
					"               .::(@:. \n";
			file.close();
		}
	}
};