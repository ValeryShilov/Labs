#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

//����������� ��� ����������
Book::Book()
{
	name = "";
	author = "";
	year = 0;
	cout << "����������� ��� ���������� ��� �������: " << this << endl;
}
//����������� � �����������
Book::Book(string N, string K, int S)
{
	name = N;
	author = K;
	year = S;
	cout << "����������� � ����������� ��� �������: " << this << endl;
}
//����������� �����������
Book::Book(const Book& t)
{
	name = t.name;
	author = t.author;
	year = t.year;
	cout << "����������� ����������� ��� �������: " << this << endl;
}
//����������
Book::~Book()
{
	cout << "���������� ��� �������: " << this << endl;
}
//���������
string Book::get_name()
{
	return name;
}
string Book::get_author()
{
	return author;
}
int Book::get_year()
{
	return year;
}
//������������
void Book::set_name(string N)
{
	name = N;
}
void Book::set_author(string K)
{
	author = K;
}
void Book::set_year(int S)
{
	year = S;
}
//����� ��� ��������� ���������
void Book::show()
{
	cout << "name: " << name << endl;
	cout << "author: " << author << endl;
	cout << "year: " << year << endl;
}