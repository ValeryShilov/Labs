#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;
Vector::Vector(int s)
{
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
Vector::~Vector()
{
	if (beg != 0) delete[]beg;
}
Vector::Vector(int s, int* mas)
{
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
const Vector& Vector::operator =(const Vector& v)
{
	if (this == &v) return *this;
	if (beg != 0) delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
int Vector::operator [](int i)
{
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return beg[i];
}

int Vector::operator()(int s)
{
	return size;
}

Vector Vector::operator+(int n)
{
	if ((size + n) > MAX_SIZE) throw MaxSizeError();
	if (n < 0) throw NegSizeError();
	int s = size + n;
	int* beg1 = new int[s];
	for (int i = 0; i < size; i++)
	{
		beg1[i] = beg[i];
	}
	for (int i = size; i < s; i++)
	{
		int el;
		cin >> el;
		beg1[i] = el;
	}
	Vector temp(s, beg1);
	return temp;
}

Vector Vector::operator-(int n)
{
	if (n > size) throw NSizeError();
	if (size == 0) throw EmptySizeError();
	int s = size - n;
	int* beg1 = new int[s];
	for (int i = 0; i < s; i++)
	{
		beg1[i] = beg[i];
	}
	Vector temp(s, beg1);
	return temp;
}
