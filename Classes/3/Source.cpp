#include "Time.h"
#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251");
	system("cls");
	Time a;
	Time b;
	Time sum;
	cin >> a;//ввод переменной
	cin >> b;//ввод переменной
	sum = a - b;//префиксна€ операци€ инкремент
	if (a != b) cout << "a и b не равны" << endl;
	else cout << "a и b равны" << endl;
	cout << "–азность = " << sum << endl;//вывод переменной
	cout << "a = " << a << endl; //вывод переменной
	cout << "b = " << b << endl; //вывод переменной
	cout << "sum = " << sum << endl; //вывод переменной
	return 0;
}