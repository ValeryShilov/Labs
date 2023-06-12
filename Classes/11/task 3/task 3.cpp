#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include "vector.h"
#include <iostream>
using namespace std;

void main()
{
	Vector<Time>vec(5);
	vec.Print();
	Time temp;
	temp = vec.max();
	cout << temp << endl;
	vec.add(temp);
	vec.Print();
	int mini;
	mini = vec.min();
	cout << mini << endl;
	vec.del(mini);
	vec.Print();
	vec.sred();
	temp = vec.sred();
	cout << temp << endl;
	vec.add_sred(temp);
	vec.Print();
}