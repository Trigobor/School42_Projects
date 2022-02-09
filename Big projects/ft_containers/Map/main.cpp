#include "Map.hpp"
#include <map>

int main()
{
	ft::map<int, std::string > ft_map_one;
	std::map<int, std::string > std_map_one;

	std::cout << "---------------------------------------------\n";

	std::cout << "ft map status:\n";
	if (ft_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << ft_map_one.max_size() << "\n";
	std::cout << "  current size is " << ft_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "std map status:\n";
	if (std_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << std_map_one.max_size() << "\n";
	std::cout << "  current size is " << std_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	ft_map_one.insert(ft::make_pair(42, "forty two"));
	ft_map_one.insert(ft::make_pair(10, "ten"));
	ft_map_one.insert(ft::make_pair(6, "six"));
	ft_map_one.insert(ft::make_pair(100, "hundred"));
	ft_map_one.insert(ft::make_pair(1000, "thousand"));
	ft_map_one.insert(ft::make_pair(1000, "lol"));
	ft_map_one.insert(ft::make_pair(-1, "minus one"));
	std_map_one.insert(std::make_pair(42, "forty two"));
	std_map_one.insert(std::make_pair(10, "ten"));
	std_map_one.insert(std::make_pair(6, "six"));
	std_map_one.insert(std::make_pair(100, "hundred"));
	std_map_one.insert(std::make_pair(1000, "thousand"));
	std_map_one.insert(std::make_pair(1000, "lol"));
	std_map_one.insert(std::make_pair(-1, "minus one"));

	std::cout << "\nI added 42, 10, 6, 100, 1000(two times) and -1\n binded with it string names to both of maps\n\n";
	std::cout << "---------------------------------------------\n";

	std::cout << "ft map status:\n";
	if (ft_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << ft_map_one.max_size() << "\n";
	std::cout << "  current size is " << ft_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "std map status:\n";
	if (std_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << std_map_one.max_size() << "\n";
	std::cout << "  current size is " << std_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "\nI will try to use at() method with a wrong (12)\nargument\n\n";

	try
	{
		ft_map_one.at(12);
	}
	catch(const std::exception& e)
	{
		std::cout << "ft error messege:  ";
		std::cerr << e.what();
	}
	
	try
	{
		std_map_one.at(12);
	}
	catch(const std::exception& e)
	{
		std::cout << "\nstd error messege: ";
		std::cerr << e.what() << "\n\n";
	}

	std::cout << "---------------------------------------------\n";

	std::cout << "\nI will try to use at() method with a correct\n(10) argument\n\n";

	try
	{
		std::cout << "ft::map = " << ft_map_one.at(10) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "ft error messege:  ";
		std::cerr << e.what();
	}
	
	try
	{
		std::cout << "std::map = " << std_map_one.at(10) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "\nstd error messege: ";
		std::cerr << e.what() << "\n\n";
	}

	std::cout << "\n---------------------------------------------\n";

	std::cout << "\nI will try to use operator[] method with a \ncorrect (1000) argument and we will see which \none of (1000) value was added erlier \n\n";

	std::cout << "ft::map = " << ft_map_one[1000] << '\n';
	std::cout << "std::map = " << std_map_one[1000] << '\n';

	std::cout << "\n---------------------------------------------\n";

	std::cout << "\nI will try to use operator[] method with a \nuncorrect (43) argument. I wonder what will happen\n\n";

	std::cout << "ft::map = " << ft_map_one[43] << '\n';
	std::cout << "std::map = " << std_map_one[43] << '\n';

	std::cout << "\nWow! Look! Nothing!\n\n---------------------------------------------\n";

	ft::map<int, std::string >::iterator ft_begin_iterator = ft_map_one.begin();
	ft::map<int, std::string >::iterator ft_end_iterator = ft_map_one.end();

	std::map<int, std::string >::iterator std_begin_iterator = std_map_one.begin();
	std::map<int, std::string >::iterator std_end_iterator = std_map_one.end();

	std::cout << "\nI created iterartors, pointig to begin(), \nand end() to both of maps\n\n";

	std::cout << "ft iterator begin pointing to pair <" << ft_begin_iterator->first << ", " << ft_begin_iterator->second << ">\n";
	std::cout << "std iterator begin pointing to pair <" << std_begin_iterator->first << ", " << std_begin_iterator->second << ">\n";

	std::cout << "\n---------------------------------------------\n";

	std::cout << "\nI will test iterator operator++\n\nft iterator test:\n";
	while (ft_begin_iterator != ft_end_iterator)
	{
		std::cout << "ft iterator pointing to pair <" << ft_begin_iterator->first << ", " << ft_begin_iterator->second << ">\noperator++\n";
		ft_begin_iterator++;
	}

	std::cout << "\nstd iterator test:\n";

	while (std_begin_iterator != std_end_iterator)
	{
		std::cout << "std iterator pointing to pair <" << std_begin_iterator->first << ", " << std_begin_iterator->second << ">\noperator++\n";
		std_begin_iterator++;
	}

	std::cout << "\n---------------------------------------------\n";

	std::cout << "ft map status:\n";
	if (ft_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << ft_map_one.max_size() << "\n";
	std::cout << "  current size is " << ft_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "std map status:\n";
	if (std_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << std_map_one.max_size() << "\n";
	std::cout << "  current size is " << std_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "\nTesting count method\n";

	std::cout << "\nft map correct val scenario (10):\n";
	std::cout << "There is " << ft_map_one.count(10) << " node with (10) key\n";

	std::cout << "\nft map uncorrect val scenario (12):\n";
	std::cout << "There is " << ft_map_one.count(12) << " node with (12) key\n";
	
	std::cout << "\nstd map correct val scenario (10):\n";
	std::cout << "There is " << std_map_one.count(10) << " node with (10) key\n";

	std::cout << "\nstd map uncorrect val scenario (12):\n";
	std::cout << "There is " << std_map_one.count(12) << " node with (12) key\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "\nTesting find method\n";

	ft::map<int, std::string >::iterator ft_iterator = ft_map_one.find(10);

	std::map<int, std::string >::iterator std_iterator = std_map_one.find(10);

	std::cout << "\nft map:\n";
	std::cout << "There is " << ft_iterator->first << " node with (10) key\n";
	
	std::cout << "\nstd map:\n";
	std::cout << "There is " << std_iterator->first << " node with (10) key\n";

	//дополни тесты когда перепишешь end()

	std::cout << "\n---------------------------------------------\n";

	std::cout << "\nTesting upper/lower_bound method with (10) as hint\n";

	std::cout << "\nft map upper_bound:\n";
	std::cout << "There is (" << ft_map_one.upper_bound(10)->second << ") node with (10) key";
	
	std::cout << "\nstd map upper_bound:\n";
	std::cout << "There is (" << std_map_one.upper_bound(10)->second << ") node with (10) key";

	std::cout << "\nft map lower_bound:\n";
	std::cout << "There is (" << ft_map_one.lower_bound(10)->second << ") node with (10) key";
	
	std::cout << "\nstd map lower_bound:\n";
	std::cout << "There is (" << std_map_one.lower_bound(10)->second << ") node with (10) key\n";

	std::cout << "\nTesting upper/lower_bound method with (3) as hint\n";

	std::cout << "\nft map upper_bound:\n";
	std::cout << "There is (" << ft_map_one.upper_bound(3)->second << ") node with (3) key";
	
	std::cout << "\nstd map upper_bound:\n";
	std::cout << "There is (" << std_map_one.upper_bound(3)->second << ") node with (3) key";

	std::cout << "\nft map lower_bound:\n";
	std::cout << "There is (" << ft_map_one.lower_bound(3)->second << ") node with (3) key";
	
	std::cout << "\nstd map lower_bound:\n";
	std::cout << "There is (" << std_map_one.lower_bound(3)->second << ") node with (3) key\n";

	std::cout << "\n---------------------------------------------\n";
/*
//	вызывает ошибку компиляции и в моем и в штатном случае

	std::cout << "ft key_comp: " << ft_map_one.key_comp() << "\n";
	std::cout << "std key_comp: " << std_map_one.key_comp() << "\n\n";

	std::cout << "ft value_comp: " << ft_map_one.value_comp() << "\n";
	std::cout << "std value_comp: " << std_map_one.value_comp() << "\n";

	std::cout << "\n---------------------------------------------\n";
*/

	std::cout << "\nmaking erase() from begin to begin+3 this will erase -1, 6, 10\n\n---------------------------------------------\n";

	ft::map<int, std::string>::iterator begin_ft = ft_map_one.begin();
	std::map<int, std::string>::iterator begin_std = std_map_one.begin();

	for (int i = 0; i < 3; i++)
	{
		begin_ft++;
		begin_std++;
	}

	std_map_one.erase(std_map_one.begin(), begin_std);
	ft_map_one.erase(ft_map_one.begin(), begin_ft);

	std::cout << "\nI will try to use at() method with a correct\n(-1) argument\n\n";

	try
	{
		std::cout << "\nft::map = " << ft_map_one.at(-1) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "ft error messege:  ";
		std::cerr << e.what();
	}
	
	try
	{
		std::cout << "\nstd::map = " << std_map_one.at(-1) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "std error messege: ";
		std::cerr << e.what() << "\n\n";
	}

	std::cout << "\nI will try to use at() method with a correct\n(6) argument\n\n";

	try
	{
		std::cout << "\nft::map = " << ft_map_one.at(6) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "ft error messege:  ";
		std::cerr << e.what();
	}
	
	try
	{
		std::cout << "\nstd::map = " << std_map_one.at(6) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "std error messege: ";
		std::cerr << e.what() << "\n\n";
	}

	std::cout << "\nI will try to use at() method with a correct\n(10) argument\n\n";

	try
	{
		std::cout << "\nft::map = " << ft_map_one.at(10) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "ft error messege:  ";
		std::cerr << e.what();
	}
	
	try
	{
		std::cout << "\nstd::map = " << std_map_one.at(10) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "std error messege: ";
		std::cerr << e.what() << "\n\n";
	}

	std::cout << "\n---------------------------------------------\n";

	std_map_one.clear();
	ft_map_one.clear();

	std::cout << "\nmaking clear()\n\n---------------------------------------------\n";

	std::cout << "ft map status:\n";
	if (ft_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << ft_map_one.max_size() << "\n";
	std::cout << "  current size is " << ft_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	std::cout << "std map status:\n";
	if (std_map_one.empty())
		std::cout << "  map is empty\n";
	else
		std::cout << "  map isn't empty\n";
	std::cout << "  max size is " << std_map_one.max_size() << "\n";
	std::cout << "  current size is " << std_map_one.size() << "\n";

	std::cout << "---------------------------------------------\n";

	ft::map<int, std::string > ft_map_two;
	if (ft_map_one == ft_map_two)
		std::cout << "\nall good\n";
	else
		std::cout << "\nsomething went wrong\n";

	return 0;
};
