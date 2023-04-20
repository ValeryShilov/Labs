#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
//функция для возврата объекта как результата
Book make_Book()
{
	string s;
	string i;
	double d;
	cout << "Vvedite name: ";
	cin >> s;
	cout << "Vvedite author: ";
	cin >> i;
	cout << "Vvedite year: ";
	cin >> d;
	Book t(s, i, d);
	return t;
}
//функция для передачи объекта как параметра
void print_Book(Book t)
{
	t.show();
}
void main()
{
	setlocale(0, "");
	//конструктор без параметров
	Book t1;
	t1.show();
	//коструктор с параметрами
	Book t2("Война и мир", "Л.Н.Толстой", 1867);
	t2.show();
	//конструктор копирования
	Book t3 = t2;
	t3.set_name("Отцы и дети");
	t3.set_author("И.С.Тургенев");
	t3.set_year(1923);
	//конструктор копирования
	print_Book(t3);
	//конструктор копирования
	t1 = make_Book();
	t1.show();
}