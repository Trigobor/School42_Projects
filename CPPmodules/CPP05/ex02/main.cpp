#include "Bureaucrat.hpp"
#include "StrawberryForm.hpp"
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp" 

int main()
{
	try
	{
		Bureaucrat Mike("Mike", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Sally("Sally");
		Sally.setGrade(0);
	}
	catch(std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Randel("Randel", 150);
		Randel.decGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	Bureaucrat Boo("Boo", 1);
	std::cout << "before " << Boo << std::endl;
	Boo.decGrade();
	std::cout << "after " << Boo << std::endl;
	Form *tree = new StrawberryForm();
	try
	{
		tree->execute(Boo);
	}
	catch(std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	Bureaucrat Burecrafter("Burecrafter", 150);
	std::cout << Burecrafter << std::endl;
	try
	{
		tree->execute(Burecrafter);
	}
	catch(const std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	Boo.signForm(*tree);
	try
	{
		tree->execute(Burecrafter);
	}
	catch(const std::exception& e)
	{
		std::cout << "Исключение было поймано: " << e.what() << std::endl;
	}
	tree->execute(Boo);

	Form *robo = new RobotomyRequestForm();
	Form *pard = new PresidentialPardonForm();
	Boo.signForm(*pard);
	pard->execute(Boo);
	Boo.signForm(*robo);
	robo->execute(Boo);
}