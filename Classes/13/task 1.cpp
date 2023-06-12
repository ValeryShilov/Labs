#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<Time> TVector;


TVector make_vector(int n)
{
	Time a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a; v.push_back(a);
	}
	return v;
}

void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << endl; cout << endl;
}
Time srednee(TVector v)
{
	Time s = v[0];
	
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size();
	return s / n;
}
void add(Time& t, Time& average)
{
	t = t + average;
}
void main()
{
	int n; cout << "N? ";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);

	TVector::iterator i;
	

	cout << endl;

	i = max_element(v.begin(), v.end());
	Time m = *(i);
	Time a;
	cin >> a;
	cout << endl;
	replace(v.begin(), v.end(), m, a);
	print_vector(v);

	cout << endl;

	i = min_element(v.begin(), v.end());
	m = *(i);
	i = remove(v.begin(), v.end(), m);
	v.erase(i, v.end());
	print_vector(v);

	cout << endl;

	Time s;
	s = srednee(v);
	for_each(v.begin(), v.end(), [&](Time& t) {
		add(t, s);
		});
	print_vector(v);
}