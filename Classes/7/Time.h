#pragma once
#include <iostream>
using namespace std;
class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	friend Time operator+(Time k1, Time k2);
	//перегруженные операции ввода-вывода
	friend ostream& operator<< (ostream& out, const Time&);
	friend istream& operator>> (istream& in, Time&);
public:
	virtual ~Time(void) {};
private:
	int min, sec;
};

