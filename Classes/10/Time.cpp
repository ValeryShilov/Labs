#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;

bool Time::operator!=(const Time& t)
{
	if (t.min != min && t.sec != sec)
	{
		return true;
	}
	else return false;
}

ostream& operator << (ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "min? "; in >> t.min;
	cout << "sec? "; in >> t.sec;
	return in;
}

fstream& operator>>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}
fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << ":" << t.sec;
	return fout;
}