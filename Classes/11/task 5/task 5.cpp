#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include <iostream>
#include <stack> 
#include <vector>
#include "vector.h"
using namespace std;

void  main()
{
	Vector<Time>v(3);
	v.Print();
	cout << endl;
	v.Add();
	v.Print();
	cout << endl;
	v.Del();
	v.Print();
	cout << endl;
	Time e;
	e = v.Srednee();
	v.Add_sred(e);
	v.Print();
	cout << endl;
}