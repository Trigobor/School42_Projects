#include "Stack.hpp"
#include <stack>
#include <vector>

int main()
{
	ft::stack<int> a;
	std::stack<int> b;

	std::cout << "test block 1\na size " << a.size() << std::endl;
	std::cout << "b size " << b.size() << std::endl;

//	std::cout << "a top " << a.top() << std::endl; //приведет к сеге
//	std::cout << "b top " << b.top() << std::endl; //приведет к сеге

	std::cout << "a empty " << a.empty() << std::endl;
	std::cout << "b empty " << b.empty() << std::endl;

	a.push(1);
	std::cout << "a pushed\n";
	b.push(1);
	std::cout << "b pushed\n";

	std::cout << "a size " << a.size() << std::endl;
	std::cout << "b size " << b.size() << std::endl;

	std::cout << "a top " << a.top() << std::endl;
	std::cout << "b top " << b.top() << std::endl;

	std::cout << "a empty " << a.empty() << std::endl;
	std::cout << "b empty " << b.empty() << std::endl;

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	ft::stack<int, std::vector<int> > c(v);
	std::stack<int, std::vector<int> > d(v);
	std::cout << "\n\ntest block 2\nc size " << c.size() << std::endl;
	std::cout << "d size " << d.size() << std::endl;
	std::cout << "c top " << c.top() << std::endl;
	std::cout << "d top " << d.top() << std::endl;
	std::cout << "c empty " << c.empty() << std::endl;
	std::cout << "d empty " << d.empty() << std::endl;

	ft::stack<int> e;
	std::stack<int> f;
	e.push(2);
	f.push(2);

	std::cout << "\n\ntest block 3\nft::stack operators: a is " << a.top() << ", e is " << e.top() << std::endl;
	std::cout << "a == e? " << (a == e) << std::endl;
	std::cout << "a != e? " << (a != e) << std::endl;
	std::cout << "a <= e? " << (a <= e) << std::endl;
	std::cout << "a >= e? " << (a >= e) << std::endl;
	std::cout << "a < e? " << (a < e) << std::endl;
	std::cout << "a > e? " << (a > e) << std::endl;
	std::cout << "std::stack operators: b is " << b.top() << ", f is " << f.top() << std::endl;
	std::cout << "b == f? " << (b == f) << std::endl;
	std::cout << "b != f? " << (b != f) << std::endl;
	std::cout << "b <= f? " << (b <= f) << std::endl;
	std::cout << "b = f? " << (b >= f) << std::endl;
	std::cout << "b r< f? " << (b < f) << std::endl;
	std::cout << "b > f? " << (b > f) << std::endl;
	
	b = f;
	a = e;
	std::cout << "\n\ntest block 4\na is " << a.top() << "\nb is " << b.top() << std::endl;
}