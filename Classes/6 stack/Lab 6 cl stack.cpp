#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
	system("chcp 1251 > nul");
	srand(time(NULL));
	Stack a(10);
	cout << a << endl;
	cout << "Первый элемент: " << a.front() << endl << endl;
	for (int i = 0; i < a(); i++) a[i] = rand() % 100 - 40;
	cout << a << endl;
	Stack b(a); 
	cout << "Стек скопирован\n";
	cout << b << endl;
	int num;
	cout << "a + a: " << a + a << endl;
	cout << "Введите число для добавления: "; cin >> num;
	b.push(num);
	cout << b << endl;
	cout << "Удаление первого элемента" << endl;
	b.pop();
	cout << b << endl;

	return 0;
}