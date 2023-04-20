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
	~Book();//����������
	string get_name();//��������
	void set_name(string);//�����������
	string get_author();//��������
	void set_author(string); //�����������
	int get_year();//��������
	void set_year(int); //�����������
	void show();//�������� ���������
};

