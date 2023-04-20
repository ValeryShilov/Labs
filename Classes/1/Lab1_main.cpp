#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(0, "");
	fraction A;
	cout << "¬ведите номинал купюры" << endl;
	cin >> A.first;
	cout << "¬ведите количество купюр" << endl;
	cin >> A.second;
	cout << "—умма" << endl;
	cout << A.summa() << endl;
	return 0;
}