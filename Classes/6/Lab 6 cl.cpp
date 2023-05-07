#include "List.h"
#include <iostream>

int main()
{
    system("chcp 1251 > nul");
	List l1(5);
	cout << "Первый список l1: " << endl << l1 << endl;
	cout << "Длина списка: " << l1() << endl;
	cout << "Первый элемент спиcка: " << l1[0] << endl;
	cout << "Последний элемент списка: " << l1[l1() - 1] << endl;

	List l2;
	cout << endl << "Второй список l2: " << endl;
	cin >> l2;
	cout << l2 << endl;

	List l3;
	l3 = l1 + l2;
	cout << "Третий список l3=l1+l2: "<< endl << l3 << endl;

	List l4(7);
	cout << "Четвертый список: " << endl << l4 << endl;
	int n;
	Iterator i = l4.f();
	cout << "Введите индекс элемента списка, к которому хотите перейти: "; cin >> n;
	i = i + n;
	cout << "Элемент под индексом " << n << ": " << *i << endl;

	return 0;
}

