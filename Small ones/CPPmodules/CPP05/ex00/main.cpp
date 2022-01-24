#include "Bureaucrat.hpp"

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
	Bureaucrat Boo("Boo", 40);
	std::cout << "before " << Boo << std::endl;
	Boo.incGrade();
	std::cout << "after " << Boo << std::endl;
}