#include "Point.hpp"

int main() {
	std::cout << "Expected output: false false false false (all tested points are on an edge or outside)" << std::endl;
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(5, 5);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(10, 10);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(5, 0);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(0, 5);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	std::cout << "Expected output: true true true (all tested points are strictly inside the triangle)" << std::endl;
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(1, 1);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(2, 2);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 0);
		Point c = Point(0, 10);
		Point p = Point(5, 1);
		std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	}
	return 0;
}