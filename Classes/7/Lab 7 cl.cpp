#include <iostream>
#include "Time.h"
#include "List.h"
#include <algorithm>
#include <Windows.h>


using namespace std;
int main()
{
	List<double>l1(5, 5.7);
	cout << "Список l1: " << l1 << endl;
	//Ввод и вывод значений списка
	cout << "Список l2: " << endl;
	List<double>l2;
	cin >> l2;
	cout << "Ваш список: " << l2 << endl;
	//Операция присваивания
	List<double>l3;
	cout << "Копирование из l2 в l3: " << endl;
	l3 = l2;
	cout << "Ваш список: " << l3;
	int n;
	cout << "Элемент под каким номером вы хотите получить? "; cin >> n;
	cout << "Элемент под номером " << n << ": " << '[' << l3[n - 1] << ']' << endl; //Доступ по индексу
	cout << "Длина списка: " << l3() << endl << endl; //Получение длины списка

	List<double>l4;
	l4 = l3 + l1; //Операция сложения элементов списков a[i]+b[i]
	cout << "Сложение элементов двух списков l4=l3+l1: " << l4 << endl;

	cout << "Введите экзепляр t1:" << endl;
	Time t1;
	cin >> t1;
	cout << "Ваш экземпляр: " << t1 << endl << endl;

	cout << "Введите экзепляр t2:" << endl;
	Time t2;
	cin >> t2;
	cout << "Ваш экземпляр: " << t2 << endl << endl;

	Time t3;
	t3 = t2 + t1;
	cout << "Экземпляр t3=t2+t1: " << t3 << endl << endl;

	cout << "Список l5, состоящий из экземпляра t3: " << endl;
	List<Time>l5(5, t3);
	cout << l5 << endl;

	cout << "Список l6, состоящий из элемнтов типа Time:" << endl;
	List<Time>l6;
	cin >> l6;
	cout << l6 << endl;

	cout << "Копирование из l6 в l7: " << endl;
	List<Time>l7;
	l7 = l6;
	cout << "Ваш список: " << l7;
	int i;
	cout << "Элемент под каким номером вы хотите получить? "; cin >> i;
	cout << "Элемент под номером " << i << ": " << '[' << l7[i - 1] << ']' << endl;
	cout << "Длина списка: " << l7() << endl;

	List<Time>l8;
	l8 = l7 + l5;
	cout << "Сложение элементов двух списков l8=l7+l5: " << l8 << endl;
	return 0;	
}

