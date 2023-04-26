#include "Pair.h"
#include <iostream>
using namespace std;

Pair::~Pair()
{
}

Pair& Pair::operator=(const Pair& c)
{
	if (&c == this)return *this;
	first = c.first;
	second = c.second;
	return *this;
}
//���������� ������� ��� �����
istream& operator>>(istream& in, Pair& c)
{
	cout << "\nFirst: "; in >> c.first;
	cout << "\nSecond: "; in >> c.second;
	return in;
}
//���������� ������� ��� ������
ostream& operator<<(ostream& out, const Pair& c)
{
	out << "\nFirst : " << c.first;
	out << "\nSecond : " << c.second;
	out << "\n";
	return out;
}

int Pair::mult()
{
	return first * second;
}

int Pair::sum()
{
	return first + second;
}