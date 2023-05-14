#include "Emloyee.h"
#include <iostream>
using namespace std;

Emloyee::Emloyee()
{
	salary = 0;
	post = " ";
}

Emloyee::Emloyee(float s, string p)
{
	salary = s;
	post = p;
}

Emloyee::~Emloyee()
{

}

Emloyee::Emloyee(const Emloyee& temp)
{
	salary = temp.salary;
	post = temp.post;
}

void Emloyee::Show()
{
	cout << "Salary: " << salary << endl;
	cout << "Job title: " << post << endl;
}

void Emloyee::Input()
{
	cout << "Input salary: "; cin >> salary;
	cout << "Input job title: "; cin >> post;
}

void Emloyee ::set_salary(float s)
{
	salary = s;
}

void Emloyee::set_post(string p)
{
	post = p;
}

Emloyee& Emloyee::operator=(const Emloyee& temp)
{
	if (this == &temp) return *this;
	salary = temp.salary;
	post = temp.post;
	return *this;
}