#include "Human.h"
#include <iostream>
#include "Event.h"
using namespace std;

Human::Human()
{
	name = " ";
	age = 0;
}

Human::~Human()
{
}

Human::Human(string n, int a)
{
	name = n;
	age = a;
}

Human::Human(const Human& h)
{
	name = h.name;
	age = h.age;
}

void Human::Show()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Human::Input()
{
	cout << "Input name: "; cin >> name;
	cout << "Input age: "; cin >> age;
}

void Human::set_name(string n)
{
	name = n;
}

void Human::set_age(int a)
{
	age = a;
}

Human& Human::operator=(const Human& h)
{
	name = h.name;
	age = h.age;
	return *this;
}

void Human::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "name = " << get_name() << endl;
			break;
		}
	}
}