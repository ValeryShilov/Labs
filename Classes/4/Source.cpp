#include "Pair.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

void f1(Pair& p)
{
	p.set_first(5);
	cout << p;
}

Pair f2()
{
	Rectangle b(5, 9);
	return b;
}

int main()
{
	Pair a1;
	Pair b2(1,2);
	cin >> a1;
	cout << a1 << endl;
	a1 = b2;
	cout << a1 << endl;

	Rectangle a;
	Rectangle b;
	cin >> a;
	cout << a << endl;
	b = a;
	cout << b << endl;
	cout << "Square " << " = " << b.square() << endl;
	cout << "Perimeter " << " = " << b.perimeter() << endl;
	f1(b);
	Pair c = f2();
	cout << c << endl;

}