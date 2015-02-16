#include "Point.h"
#include <iostream>
int main ()
{
	Point a;
	Point b(0.1, 0.2, 0.3);
	Point c = a*b;
	a.print();
	b.print();
	c.print();
	Point d = c + a;
	Point e = c + b;
	d.print();
	e.print();
	std::cout << "a equals c?" << (a==c) << "or not?" << (a!=c)  << std::endl;
}
