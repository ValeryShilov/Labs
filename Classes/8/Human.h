#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Human :
	public Object
{
public:
	Human(void);
	void HandleEvent(const TEvent& e);
public:
	virtual~Human(void);
	void Show();
	void Input();
	Human(string, int);
	Human(const Human&);
	string get_name() { return name; }
	int get_age() { return age; }
	void set_name(string);
	void set_age(int);
	Human& operator=(const Human&);

protected:
	string name;
	int age;
};

