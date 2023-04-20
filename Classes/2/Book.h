#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
	string name;
	string author;
	int year;
public:
	Book();
	Book(string, string, int);
	Book(const Book&);
	~Book();//деструктор
	string get_name();//селектор
	void set_name(string);//модификатор
	string get_author();//селектор
	void set_author(string); //модификатор
	int get_year();//селектор
	void set_year(int); //модификатор
	void show();//просмотр атрибутов
};

