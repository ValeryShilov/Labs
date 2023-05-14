#pragma once
#include "Human.h"
#include "Object.h"
#include <iostream>
using namespace std;

class Emloyee :
	public Human
{
public:
	Emloyee(void);
public:
	~Emloyee(void);
	void Show();
	void Input();
	Emloyee(float, string);
	Emloyee(const Emloyee&);
	float get_salary() { return salary; }
	string get_post() { return post; }
	void set_salary(float);
	void set_post(string);
	Emloyee& operator=(const Emloyee&);

protected:
	float salary;
	string post;
};

