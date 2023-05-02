#pragma once
#include <iostream>
#include "Pair.h"
class Rectangle:
	public Pair
{
public:
	Rectangle() { first = 0, second = 0; }
	virtual ~Rectangle();
	Rectangle(int l, int w) { first = l, second = w; }
	Rectangle(const Rectangle& r) { first = r.first, second = r.second; }
	void Show();
	int get_leight() { return first; }
	int get_width() { return second; }
	void set_leight(int l) { first = l; }
	void set_width(int w) { second = w; }
	Rectangle& operator=(const Rectangle&);
	friend istream& operator>>(istream& in, Rectangle& c);
	friend ostream& operator<<(ostream& out, const Rectangle& c);
	int square();
	int perimeter();
};

