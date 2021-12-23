#include <iostream>
#include <fstream>

void	rep(std::string &str, std::string s1, std::string s2)
{
	size_t i = 0;

	while (true)
	{
		i = str.find(s1, i);
		if (i != std::string::npos)
		{
			str.erase(i, s1.length());
			str.insert(i, s2);
			i += s2.length();
		}
		else
			return ;
	}
}

int	main(int ac, char **av)
{
	std::string	filename;

	if (ac != 4)
	{
		std::cerr << "Trying to break the program is bad, m'kay?" << std::endl;
		exit(1);
	}
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Do not put the empty strings, m'kay?" << std::endl;
		exit(1);
	}
	filename = av[1];
	std::ifstream in(filename);
	std::ofstream out(filename + ".replace");
	if (!in.is_open() || !out.is_open())
	{
		std::cerr << "Ops! There is some problem(s) with files" << std::endl;
		exit (1);
	}
	std::string	file;
	char	buff[10];
	while (true)
	{
		in.getline(buff, 10, '\n');
		file += buff;
		if (in.eof())
		{
			rep(file, s1, s2);
			out << file;
			break ;
		}
		else if (in.fail())
			in.clear();
		else
		{
			rep(file, s1, s2);
			file += '\n';
			out << file;
			file.clear();
		}
	}
	in.close();
	out.close();
	return 0;
}
