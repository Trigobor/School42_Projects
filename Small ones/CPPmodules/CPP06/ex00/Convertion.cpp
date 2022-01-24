#include "Convertion.hpp"

Convertion::Convertion(std::string arg) : valint(0), valchr(48), valflt(0), valdbl(0)
{
//	this->states = {"TBA", "all good", "imposible", "non displayable", "in process"};
//	this->status = {"TBA", "TBA", "TBA", "TBA"};
	this->status[0] = "TBA";
	this->status[1] = "TBA";
	this->status[2] = "TBA";
	this->status[3] = "TBA";
	std::stringstream tmp;
	int len = arg.length();
	int i = 0;
	if (len == 1 && !std::isdigit(arg[0]))
	{
		this->valchr = arg[0];
		this->status[1] = "all good";
	}
	else
	{
		char *cstr = (char *)arg.c_str();
		if (arg[0] == '+' || arg[0] == '-')
			i++;
		for (; i < len && std::isdigit(cstr[i]); i++){}
		if (i == len && std::isdigit(cstr[i - 1]))
		{
			this->status[0] = "all good";
			tmp << arg;
			tmp >> this->valint;
		}
		else if (cstr[i] == '.')
			i++;
		for (; i < len && std::isdigit(cstr[i]); i++){}
		if (i == len && std::isdigit(cstr[i - 1]))
		{
			this->status[2] = "TBA";
			this->status[3] = "all good";
			tmp << arg;
			tmp >> this->valdbl;
		}
		else if (i == len - 1 && cstr[i] == 'f')
		{
			this->status[3] = "TBA";
			this->status[2] = "all good";
			tmp << arg.substr(0, len - 1);
			tmp >> this->valflt;
		}
		else if (arg == "+inf" || arg == "-inf" || arg == "nan")
		{
			this->status[0] = "impossible";
			this->status[1] = "impossible";
			this->status[2] = arg + "f";
			this->status[3] = arg;
		}
		else if (arg == "+inff" || arg == "-inff" || arg == "nanf")
		{
			this->status[0] = "impossible";
			this->status[1] = "impossible";
			this->status[2] = arg;
			this->status[3] = arg.substr(0, arg.length() - 1);
		}
		else
			throw InvalidType();
		this->transformation();
	}
};

Convertion::~Convertion()
{};

int Convertion::getInt()
{return this->valint;};

char Convertion::getChar()
{return this->valchr;};

float Convertion::getFloat()
{return this->valflt;};

double Convertion::getDouble()
{return this->valdbl;};

std::string Convertion::getStatus(int i)
{
	if (i >= 0 && i < 4)
		return this->status[i];
	return NULL;
};

void Convertion::transform(int i)
{
	this->valchr = static_cast<char>(i);
	this->valflt = static_cast<float>(i);
	this->valdbl = static_cast<double>(i);
	if (!(std::isprint(this->valchr)))
		this->status[1] = "non displayble";
	if (this->valint <= 0 || this->valint > 127)
		this->status[1] = "impossible";
};

void Convertion::transform(char i)
{
	this->valint = static_cast<int>(i);
	this->valflt = static_cast<float>(i);
	this->valdbl = static_cast<double>(i);
	if (!(std::isprint(this->valchr)))
		this->status[1] = "non displayble";
	if (this->valint <= 0 || this->valint > 127)
		this->status[1] = "impossible";
};

void Convertion::transform(float i)
{
	this->valint = static_cast<int>(i);
	this->valchr = static_cast<char>(i);
	this->valdbl = static_cast<double>(i);
	if (!(std::isprint(this->valchr)))
		this->status[1] = "non displayble";
	if (this->valint <= 0 || this->valint > 127)
		this->status[1] = "impossible";
};

void Convertion::transform(double i)
{
	this->valint = static_cast<int>(i);
	this->valchr = static_cast<char>(i);
	this->valflt = static_cast<float>(i);
	if (!(std::isprint(this->valchr)))
		this->status[1] = "non displayble";
	if (this->valint <= 0 || this->valint > 127)
		this->status[1] = "impossible";
};

void Convertion::transformation()
{
	int i = 0;
	for (; i < 4 && (this->status[i] != "all good"); i++){}
	switch(i)
	{
		case(0):
		{
			transform(this->valint);
			break ;
		}
		case(1):
		{
			transform(this->valchr);
			break ;
		}
		case(2):
		{
			transform(this->valflt);
			break ;
		}
		case(3):
		{
			transform(this->valdbl);
			break ;
		}
	}
};

std::ostream& operator<<( std::ostream &stream, Convertion &sample)
{
	if (sample.getStatus(0) != "all good" && sample.getStatus(0) != "TBA")
		stream << "int: " << sample.getStatus(0) << std::endl;
	else
		stream << "int: " << sample.getInt() << std::endl;
	if (sample.getStatus(1) != "all good" && sample.getStatus(1) != "TBA")
		stream << "char: " << sample.getStatus(1) << std::endl;
	else
		stream << "char: " << sample.getChar() << std::endl;
	if (sample.getStatus(2) != "all good" && sample.getStatus(2) != "TBA")
		stream << "float: " << sample.getStatus(2) << std::endl;
	else
		stream << "float: " << sample.getFloat() << "f" << std::endl;
	if (sample.getStatus(3) != "all good" && sample.getStatus(3) != "TBA")
		stream << "double: " << sample.getStatus(3) << std::endl;
	else
		stream << "double: " << sample.getDouble() << std::endl;
	return (stream);
}
