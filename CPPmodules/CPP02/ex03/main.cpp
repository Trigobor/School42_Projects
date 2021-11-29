#include "Point.hpp"

int main()
{
	Point a(0.0, 0.0);
	Point b(10.0, 10.0);
	Point c(20.0, 0.0);
	Point inside(10.0, 5.0);
	Point out(-1.0, -1.1);

	std::cout << "внутри: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "снаружи: " << bsp(a, b, c, out) << std::endl;

	return 0;
}
