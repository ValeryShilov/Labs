#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Time
{
public:
	Time() { min = 0, sec = 0; }
	Time(int m, int s) { min = m, sec = s; }
	Time(const Time& t) { min = t.min, sec = t.sec; }
	bool operator!=(const Time&);
	friend ostream& operator <<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);
	friend fstream& operator>>(fstream& fin, Time& t);
	friend fstream& operator <<(fstream& fout, const Time& t);
public:
	~Time() { };
private:
	int min;
	int sec;
};

