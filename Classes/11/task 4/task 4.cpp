#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include <iostream>
#include <stack> 
#include <vector>
using namespace std;
typedef stack<Time>St;
typedef vector<Time>Vec;
Vec v;
St s;
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
Time max(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		if (m < s.top()) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
Time min(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	int a = 0;
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		if (m > s.top())
			m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
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
void add(St& s, Time time)
{
	Vec vv;
	Time t;
	while (!s.empty())
	{
		t = s.top();
		vv.push_back(t);
		s.pop();
	}
	vv.push_back(time);
	s = copy_vector_to_stack(vv);
}
void del(St& s, Time time)
{
	Time t;
	Vec vv;
	while (!s.empty())
	{
		t = s.top();
		
		if (!(t == time)) vv.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(vv);
}
void add_sred(St& s, Time time)
{
	Vec vv;
	Time temp;
	while (!s.empty())
	{
		temp = s.top() + time;
		vv.push_back(temp);
		s.pop();
	}
	s = copy_vector_to_stack(vv);
}
int main()
{
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);
	print_stack(s);
	Time temp;
	temp = max(s);
	cout << temp << endl;
	add(s, temp);
	print_stack(s);
	temp = min(s);
	cout << temp << endl;
	del(s, temp);
	print_stack(s);
	temp = sred(s);
	cout << temp << endl;
	add_sred(s, temp);
	print_stack(s);
	return 0;
}