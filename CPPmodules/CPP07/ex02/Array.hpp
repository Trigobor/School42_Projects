#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T	*item;
	unsigned int len;
public:
	Array() : item(new T[0]), len(0)
	{std::cout << "default constuctor" << std::endl;};
	Array(unsigned int i) : item(new T[i]), len(i)
	{std::cout << "unsigned int constuct" << std::endl;};
	Array(Array &sample) : len(sample.len)
	{
		this->item = new T[sample.len];
		for (int i = 0; i < (int)sample.len; i++)
			this->item[i] = sample.item[i];
		std::cout << "copy constuct" << std::endl;
	};
	~Array()
	{
		if (this->len)
			delete [] this->item;
		std::cout << "destuctor" << std::endl;
	};
	Array &operator=(Array &sample)
	{
		if (this->len)
			delete [] item;
		this->len = sample.len;
		this->item = new T[sample.len];
		for (int i = 0; i < (int)sample.len; i++)
			this->item[i] = sample.item[i];
		std::cout << "operator =" << std::endl;
		return *this;
	};

	class Err : public std::exception
	{
	public:
		const char* what() const throw()
		{return ("Out of range");}
	};

    T &operator[](int index)
    {
		if ((unsigned int)index >= this->len || index < 0)
			throw Err();
		else
		{
//			std::cout << "operator []" << std::endl;
			return this->item[index];
		}
	};

	int	size()
	{
		std::cout << "size function" << std::endl;
		return (this->len);
	};
};



#endif