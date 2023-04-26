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
	cin >> a;//ââîä ïåðåìåííîé
	cin >> b;//ââîä ïåðåìåííîé
	sum = a - b;//ïðåôèêñíàÿ îïåðàöèÿ èíêðåìåíò
	if (a != b) cout << "a è b íå ðàâíû" << endl;
	else cout << "a è b ðàâíû" << endl;
	cout << "Ðàçíîñòü = " << sum << endl;//âûâîä ïåðåìåííîé
	cout << "a = " << a << endl; //âûâîä ïåðåìåííîé
	cout << "b = " << b << endl; //âûâîä ïåðåìåííîé
	cout << "sum = " << sum << endl; //âûâîä ïåðåìåííîé
	return 0;
}
