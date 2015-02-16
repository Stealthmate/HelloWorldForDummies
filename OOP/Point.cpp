#include "Point.h"
#include <iostream>


Point::Point()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Point Point::operator=(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	return *this; 
	//Връщаме стойността на дадения обект, за да можем да chain-ваме изрази. Пример за това има след дефинициите на всички оператори.
}

Point Point::operator+(const Point &p)
{
	this->x += p.x;
	this->y += p.y;
	this->z += p.z;
	return *this;
}

Point Point::operator+(float x)
{
	this->x += x;
	this->y += x;
	this->z += x;
	return *this;
}


Point Point::operator-(const Point &p)
{
	this->x -= p.x;
	this->y -= p.y;
	this->z -= p.z;
	return *this;
}

Point Point::operator-(float x)
{
	this->x -= x;
	this->y -= y;
	this->z -= z;
	return *this;
}

Point Point::operator*(const Point &p)
{
	this->x *= p.x;
	this->y *= p.y;
	this->z *= p.z;
	return *this;
}

Point Point::operator*(float x)
{
	this->x *= x;
	this->y *= y;
	this->z *= z;
	return *this;
}

Point Point::operator/(const Point &p)
{
	this->x /= p.x;
	this->y /= p.y;
	this->z /= p.z;
	return *this;
}

Point Point::operator/(float x)
{
	this->x /= x;
	this->y /= y;
	this->z /= z;
	return *this;
}

/*

Пример за chain на операции:

a = b + c;
Тук се случва следното нещо:
a.operator=(b+c);
b+c реално е една стойност. Тази стойност идва точно от извикването на оператора +, защото b+c е еквавилентно на:
b.operator+(c);
Следователно факта че оператор+ връща стойността на this ни позволява да използваме оператора като "стойност".
Ако операторът беше от тип void и не връщаше никаква стойност, то тогава
a.operator=(b+c) би било невалидно, защото b+c е функция, която не връща стойност и тогава щеще да трябва да напишем:
b+c;
a.operator(b);
*/



//Тук просто проверяваме дали всички точки съвпадат и връщаме булева стойност.
bool Point::operator==(const Point& p)
{
	 return  this->x == p.x
	      && this->y == p.y
              && this->z == p.z;
}

bool Point :: operator!=(const Point &p)
{
	return this->x != p.x
	    || this->y != p.y
            || this->z != p.z;
}

/*
Извеждаме на стандартния изход следния текст:

Point:
x: <x>
y: <y>
z: <z>

където <x>, <y>, и <z> са координатите на точката.

*/
void Point::print()
{

	std::cout << "Point:\nx:" << this->x << "\ny:" << this->y << "\nz:" << this->z << std::endl;
}

