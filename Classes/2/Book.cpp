#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

//конструктор без параметров
Book::Book()
{
	name = "";
	author = "";
	year = 0;
	cout << "Конструктор без параметров для объекта: " << this << endl;
}
//конструктор с параметрами
Book::Book(string N, string K, int S)
{
	name = N;
	author = K;
	year = S;
	cout << "Конструктор с параметрами для объекта: " << this << endl;
}
//конструктор копирования
Book::Book(const Book& t)
{
	name = t.name;
	author = t.author;
	year = t.year;
	cout << "Конструктор копирования для объекта: " << this << endl;
}
//деструктор
Book::~Book()
{
	cout << "Деструктор для объекта: " << this << endl;
}
//селекторы
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
//модификаторы
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
//метод для просмотра атрибутов
void Book::show()
{
	cout << "name: " << name << endl;
	cout << "author: " << author << endl;
	cout << "year: " << year << endl;
}