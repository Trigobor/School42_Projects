#include "Vector.hpp"
#include <vector>

int main()
{
	//конструирование обычного итератора и вектора
	std::cout << "\nконструирование обычного std итератора и вектора\n=================================\n";

	std::vector<int> stdvecf;
	std::cout << stdvecf.size() << "\n";
	std::cout << stdvecf.capacity() << "\n";
	stdvecf.push_back(1);
	std::cout << stdvecf.size() << "\n";
	std::cout << stdvecf.capacity() << "\n";
	stdvecf.push_back(2);
	stdvecf.push_back(3);
	stdvecf.push_back(4);
	stdvecf.push_back(5);
	std::cout << stdvecf.size() << "\n";
	std::cout << stdvecf.capacity() << "\n";
	std::vector<int>::iterator stditerf;
	stditerf = stdvecf.begin();

	std::cout << "\nконструирование обычного ft итератора и вектора\n=================================\n";

	ft::vector<int> ftvecf;
	std::cout << ftvecf.size() << "\n";
	std::cout << ftvecf.capacity() << "\n";
	ftvecf.push_back(1);
	std::cout << ftvecf.size() << "\n";
	std::cout << ftvecf.capacity() << "\n";
	ftvecf.push_back(2);
	ftvecf.push_back(3);
	ftvecf.push_back(4);
	ftvecf.push_back(5);
	std::cout << ftvecf.size() << "\n";
	std::cout << ftvecf.capacity() << "\n";
	ft::vector<int>::iterator ftiterf;
	ftiterf = ftvecf.begin();

	//буленовские операции
	std::cout << "\nбуленовские опрерации\n=================================\n\nчисленно векторы равны, но буленовские операции сравнивают по адресу\n\n";

	ft::vector<int> ftvecff;
	ftvecff.push_back(1);
	ftvecff.push_back(2);
	ftvecff.push_back(3);
	ftvecff.push_back(4);
	ftvecff.push_back(5);
	ft::vector<int>::iterator ftiterff;
	ftiterff = ftvecff.begin();
	
	std::cout << "== :" << (ftiterf == ftiterff) << "\n";
	std::cout << "!= :" << (ftiterf != ftiterff) << "\n";
	std::cout << "<= :" << (ftiterf <= ftiterff) << "\n";
	std::cout << ">= :" << (ftiterf >= ftiterff) << "\n";
	std::cout << "<  :" << (ftiterf < ftiterff) << "\n";
	std::cout << ">  :" << (ftiterf > ftiterff) << "\n";

	std::cout << "\nитерирование и разыменовение std итератора\n=================================\n";
	std::cout << "\nдо итерирования *iterator : " << *stditerf;
	stditerf++;
	std::cout << "\nпосле iterator++          : " << *stditerf;
	stditerf += 3;
	std::cout << "\nпосле iterator += 3       : " << *stditerf;
	stditerf--;
	std::cout << "\nпосле iterator--          : " << *stditerf;
	stditerf -= 2;
	std::cout << "\nпосле iterator -= 2       : " << *stditerf;
	std::cout << "\niterator[0]               : " << stditerf[0];
	std::cout << "\niterator[3]               : " << stditerf[3];

	std::cout << "\n\nитерирование и разыменовение ft итератора\n=================================\n";
	std::cout << "\nдо итерирования *iterator : " << *ftiterf;
	ftiterf++;
	std::cout << "\nпосле iterator++          : " << *ftiterf;
	ftiterf += 3;
	std::cout << "\nпосле iterator += 3       : " << *ftiterf;
	ftiterf--;
	std::cout << "\nпосле iterator--          : " << *ftiterf;
	ftiterf -= 2;
	std::cout << "\nпосле iterator -= 2       : " << *ftiterf;
	std::cout << "\niterator[0]               : " << ftiterf[0];
	std::cout << "\niterator[3]               : " << ftiterf[3];

	//конструирование обычного итератора и вектора
	std::cout << "\nконструирование const std итератора и вектора\n=================================\n";

	std::vector<int> stdcvecf;
	std::cout << stdcvecf.size() << "\n";
	std::cout << stdcvecf.capacity() << "\n";
	stdcvecf.push_back(1);
	std::cout << stdcvecf.size() << "\n";
	std::cout << stdcvecf.capacity() << "\n";
	stdcvecf.push_back(2);
	stdcvecf.push_back(3);
	stdcvecf.push_back(4);
	stdcvecf.push_back(5);
	std::cout << stdcvecf.size() << "\n";
	std::cout << stdcvecf.capacity() << "\n";
	std::vector<int>::const_iterator stdciterf;
	stdciterf = stdcvecf.begin();

	std::cout << "\nконструирование const ft итератора и вектора\n=================================\n";

	ft::vector<int> ftcvecf;
	std::cout << ftcvecf.size() << "\n";
	std::cout << ftcvecf.capacity() << "\n";
	ftcvecf.push_back(1);
	std::cout << ftcvecf.size() << "\n";
	std::cout << ftcvecf.capacity() << "\n";
	ftcvecf.push_back(2);
	ftcvecf.push_back(3);
	ftcvecf.push_back(4);
	ftcvecf.push_back(5);
	std::cout << ftcvecf.size() << "\n";
	std::cout << ftcvecf.capacity() << "\n";
	ft::vector<int>::const_iterator ftciterf;
	ftciterf = ftcvecf.begin();

	std::cout << "\nбуленовские опрерации обчыного и const итераторов\n=================================\n\n";

	std::cout << "== :" << (ftiterf == ftciterf) << "\n";
	std::cout << "!= :" << (ftiterf != ftciterf) << "\n";
	std::cout << "<= :" << (ftiterf <= ftciterf) << "\n";
	std::cout << ">= :" << (ftiterf >= ftciterf) << "\n";
	std::cout << "<  :" << (ftiterf < ftciterf) << "\n";
	std::cout << ">  :" << (ftiterf > ftciterf) << "\n";

	std::cout << "\nфункции векторов\n=================================\n";

	std::vector<int> stdvector;

	ft::vector<int> ftvector;

	std::cout << "\nstd maxsize   = " << stdvector.max_size() << "\n";
	std::cout << "ft maxsize    = " << ftvector.max_size() << "\n";
	std::cout << "std empty     = " << stdvector.empty() << "\n";
	std::cout << "ft empty      = " << ftvector.empty() << "\n";

	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";

	stdvector.push_back(1);
	ftvector.push_back(1);

	std::cout << "\nstd [0] after pushback      = " << stdvector[0] << "\n";
	std::cout << "ft [0] after pushback       = " << ftvector[0] << "\n";
	std::cout << "std size after pushback     = " << stdvector.size() << "\n";
	std::cout << "ft size after pushback      = " << ftvector.size() << "\n";
	std::cout << "std capacity after pushback = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity after pushback  = " << ftvector.capacity() << "\n";

	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	stdvector.pop_back();
	ftvector.pop_back();

	std::cout << "\nstd [0] after popback       = " << stdvector[0] << "\n";
	std::cout << "ft [0] after popback        = " << ftvector[0] << "\n";
	std::cout << "std size after popback      = " << stdvector.size() << "\n";
	std::cout << "ft size after popback       = " << ftvector.size() << "\n";
	std::cout << "std capacity after popback  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity after popback   = " << ftvector.capacity() << "\n";

	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	stdvector.push_back(1);
	stdvector.push_back(2);
	stdvector.push_back(3);
	ftvector.push_back(1);
	ftvector.push_back(2);
	ftvector.push_back(3);

	std::cout << "\nstd [0] after pushback x3      = " << stdvector[0] << "\n";
	std::cout << "ft [0] after pushback x3       = " << ftvector[0] << "\n";
	std::cout << "std size after pushback x3     = " << stdvector.size() << "\n";
	std::cout << "ft size after pushback x3      = " << ftvector.size() << "\n";
	std::cout << "std capacity after pushback x3 = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity after pushback x3  = " << ftvector.capacity() << "\n";

	stdvector.push_back(4);
	stdvector.push_back(5);
	stdvector.push_back(6);

	ftvector.push_back(4);
	ftvector.push_back(5);
	ftvector.push_back(6);

	std::cout << "\nstd [0] after pushback x6      = " << stdvector[0] << "\n";
	std::cout << "ft [0] after pushback x6       = " << ftvector[0] << "\n";
	std::cout << "std size after pushback x6     = " << stdvector.size() << "\n";
	std::cout << "ft size after pushback x6      = " << ftvector.size() << "\n";
	std::cout << "std capacity after pushback x6 = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity after pushback x6  = " << ftvector.capacity() << "\n";

	std::cout << "std empty = " << stdvector.empty() << "\n";
	std::cout << "ft empty  = " << ftvector.empty() << "\n";

	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "\nmaking reserve(15)\n";

	stdvector.reserve(15);
	ftvector.reserve(15);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "\nmaking resize(10, 0)\n";

	stdvector.resize(10, 0);
	ftvector.resize(10, 0);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "\nmaking resize(20, 1)\n";

	stdvector.resize(20, 1);
	ftvector.resize(20, 1);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "\nmaking resize(10, 1)\n";

	stdvector.resize(10, 1);
	ftvector.resize(10, 1);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";


	std::cout << "\nmaking reserve(5)\n";

	stdvector.reserve(5);
	ftvector.reserve(5);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";
	
	std::cout << "\nmaking reserve(150)\n";

	stdvector.reserve(150);
	ftvector.reserve(150);
	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

//	std::vector<int>::iterator stditerone = stdvector.insert((stdvector.begin() += 3), 9);
//	ft::vector<int>::iterator ftiterone = ftvector.insert((ftvector.begin() += 3), 9);

	std::vector<int>::iterator stditerone = stdvector.begin() += 3;
	ft::vector<int>::iterator ftiterone = ftvector.begin() += 3;

	std::cout << "std iterator " << *stditerone << "\n";
	std::cout << "ft  iterator " << *ftiterone << "\n";

	std::cout << "\nmaking insert\n";

	stdvector.insert(stditerone, 30, 9);
	ftvector.insert(ftiterone, 30, 9);

/*	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
*/	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "std iterator " << *stditerone << "\n";
	std::cout << "ft  iterator " << *ftiterone << "\n";

//	блок проверки исключений раскоментируй что нужно
//	std::cout << "\nпроверка исключений\n=================================\n";
//	std::cout << "std making reserve(max_size + 1)\n";
//	stdvector.reserve(4611686018427387904);
//	std::cout << "ft making reserve(max_size + 1)\n";
//	ftvector.reserve(4611686018427387904);
//	std::cout << "\n\ncheking\n";

	std::vector<int>::iterator stditertwo = stdvector.begin() + 2;
	ft::vector<int>::iterator ftitertwo = ftvector.begin() + 2;

	std::cout << "\nmaking erase\n";

//	stditerone =  stdvector.end();
//	ftiterone =  ftvector.end();

	stditerone = stdvector.erase(stditertwo);
	ftiterone = ftvector.erase(ftitertwo);

	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "std iterator " << *stditerone << "\n";
	std::cout << "ft  iterator " << *ftiterone << "\n";

	stditerone = stdvector.end();
	ftiterone = ftvector.end();

	stdvector.insert(stditerone, 1810, 5);
	ftvector.insert(ftiterone, 1810, 5);

	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";

	std::cout << "std iterator " << *stditerone << "\n";
	std::cout << "ft  iterator " << *ftiterone << "\n";

	stdvector.push_back(1);
	ftvector.push_back(1);

	std::cout << "\nstd size      = " << stdvector.size() << "\n";
	std::cout << "ft size       = " << ftvector.size() << "\n";
	std::cout << "std capacity  = " << stdvector.capacity() << "\n";
	std::cout << "ft capacity   = " << ftvector.capacity() << "\n";
	std::cout << "\n==================================================================";
	std::cout << "\nstd vector looks like this: ";
	for (size_t i = 0; i < stdvector.size(); i++)
		std::cout << "[" << stdvector.at(i) << "] "; 
	std::cout << "\nft  vector looks like this: ";
	for (size_t i = 0; i < ftvector.size(); i++)
		std::cout << "[" << ftvector.at(i) << "] ";
	std::cout << std::endl;
	std::cout << "==================================================================\n";
}

//допиши операторы к итераторам -, +