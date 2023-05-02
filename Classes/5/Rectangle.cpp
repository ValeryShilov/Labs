#include "Rectangle.h"
#include "Object.h"
#include<iostream>
using namespace std;

Rectangle::~Rectangle()
{
}

Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this) return *this;
	first = r.first;
	second = r.second;
	return *this;
}

istream& operator>>(istream& in, Rectangle& c)
{
	cout << "\nLeight: "; in >> c.first;
	cout << "\nWidth: "; in >> c.second;
	return in;
}

ostream& operator<<(ostream& out, const Rectangle& c)
{
	out << "\nLeight: " << c.first;
	out << "\nWidth: " << c.second;
	return out;
}

void Rectangle::Show()
{
	cout << "\nLeight: " << first;
	cout << "\nWidth: " << second;
}

int Rectangle::square()
{
	return mult();
}

int Rectangle::perimeter()
{
	return sum();
}
