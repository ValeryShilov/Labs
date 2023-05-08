#include "Time.h"
#include "List.h"
#include <iostream>
using namespace std;

Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	min = M; sec = S;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}
Time& Time::operator =(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return*this;
}

Time operator+(Time k1, Time k2)
{
	int k1t = k1.min * 60 + k1.sec;
	int k2t = k2.min * 60 + k2.sec;
	int result = k1t + k2t;
	Time temp(result / 60, result % 60);
	return temp;
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "\nmin? "; in >> t.min;
	cout << "\nsec? "; in >> t.sec;
	return in;
}