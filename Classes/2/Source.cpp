#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
//������� ��� �������� ������� ��� ����������
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
//������� ��� �������� ������� ��� ���������
void print_Book(Book t)
{
	t.show();
}
void main()
{
	setlocale(0, "");
	//����������� ��� ����������
	Book t1;
	t1.show();
	//���������� � �����������
	Book t2("����� � ���", "�.�.�������", 1867);
	t2.show();
	//����������� �����������
	Book t3 = t2;
	t3.set_name("���� � ����");
	t3.set_author("�.�.��������");
	t3.set_year(1923);
	//����������� �����������
	print_Book(t3);
	//����������� �����������
	t1 = make_Book();
	t1.show();
}