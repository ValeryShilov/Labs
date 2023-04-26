#pragma once
#include <iostream>
using namespace std;


class Pair
{
public:
	Pair() { first = 0, second = 0; }
	virtual ~Pair();
	Pair(int s, int f) { first = s, second = f; }
	Pair(const Pair& p) { first = p.first, second = p.second; }
	int get_second() { return second; }
	int get_first() { return first; }
	void set_first(int f) { first = f; }
	void set_second(int s) { second = s; }
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
	int mult();
	int sum();


protected:
	int first;
	int second;

};

