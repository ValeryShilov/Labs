#include "Time.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	Time a;
	Time b;
	Time sum;
	cin >> a;//���� ����������
	cin >> b;//���� ����������
	sum = a - b;//���������� �������� ���������
	if (a != b) cout << "a � b �� �����" << endl;
	else cout << "a � b �����" << endl;
	cout << "����� = " << sum << endl;//����� ����������
	cout << "a = " << a << endl; //����� ����������
	cout << "b = " << b << endl; //����� ����������
	cout << "sum = " << sum << endl; //����� ����������
	return 0;
}