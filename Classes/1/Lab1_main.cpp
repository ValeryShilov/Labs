#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(0, "");
	fraction A;
	cout << "������� ������� ������" << endl;
	cin >> A.first;
	cout << "������� ���������� �����" << endl;
	cin >> A.second;
	cout << "�����" << endl;
	cout << A.summa() << endl;
	return 0;
}