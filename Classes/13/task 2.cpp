#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef stack<Time>St;
typedef vector<Time>Vec;
Vec v;
St s;

Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())
	{
		
		v.push_back(s.top());
		s.pop();
	}
	return v; 
}

St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[v.size() - 1 - i]);
	}
	return s;
}
void print_stack(St s)
{
	v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++)
	{
		Time temp = v[v.size() - 1 - i];
		cout << temp << " ";
	}
	cout << endl;
}
St make_stack(int n)
{
	St s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.push(t);
	}
	return s;
}
Time sred(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		m = m + s.top();
		s.pop();
	}
	m = m / n;
	s = copy_vector_to_stack(v);
	return m;
}
void add(Time& t, Time& average)
{
	t = t + average;
}
void replaceMaxElement(St& s, const Time& newValue)
{
	Vec v = copy_stack_to_vector(s);
	auto maxElementIter = max_element(v.begin(), v.end());
	if (maxElementIter != v.end()) {
		replace(v.begin(), v.end(), *maxElementIter, newValue);
		s = copy_vector_to_stack(v);
	}
}
void eraseMinElement(St& s)
{
	Vec v = copy_stack_to_vector(s);
	auto minElementIter = min_element(v.begin(), v.end());
	Time min = *minElementIter;
	minElementIter = remove(v.begin(), v.end(), min);
	v.erase(minElementIter, v.end());
	s = copy_vector_to_stack(v);
}
void for_each_add(St& s)
{
	Vec v = copy_stack_to_vector(s);
	Time sredn = sred(s);
	for_each(v.begin(), v.end(), [&](Time& t) {
		add(t, sredn);
		});
	s = copy_vector_to_stack(v);
}
int main()
{
	int n;
	cout << "N? ";
	cin >> n;
	St v;
	v = make_stack(n);
	print_stack(v);
	Time a;
	cin >> a;
	replaceMaxElement(v, a);
	print_stack(v);
	cout << endl;
	eraseMinElement(v);
	print_stack(v);
	cout << endl;
	for_each_add(v);
	print_stack(v);
	return 0;
}