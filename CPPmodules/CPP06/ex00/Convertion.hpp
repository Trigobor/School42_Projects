#ifndef CONVERTION_HPP
#define CONVERTION_HPP

# include <iostream>
# include <sstream>
# include <limits>

class Convertion
{
private:
	int valint;
	char valchr;
	float valflt;
	double valdbl;
	std::string el;
	std::string status[4];
public:
	class InvalidType : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("Invalid type");}
	};
	Convertion(std::string arg);
	~Convertion();
	int getInt();
	char getChar();
	float getFloat();
	double getDouble();
	void transformation();
	void transform(int i);
	void transform(char i);
	void transform(float i);
	void transform(double i);
	std::string getStatus(int i);
};

std::ostream& operator<<(std::ostream &stream, Convertion &sample);

#endif