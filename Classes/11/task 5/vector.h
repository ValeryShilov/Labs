#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

template<class T>
class Vector
{
	stack <T> s
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void Print();
	T Max();
	void Del();
	T Min();
	void Add();
	T Srednee();
	void Add_sred(T);
};

template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top()); s.pop();
	}
	return v;
}

template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
}

template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;

	vector<T> v = copy_stack_to_vector(Vec.s);

	s = copy_vector_to_stack(v);
}

template <class T>
void Vector<T>::Print()
{

	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Max()
{
	T m = s.top();
	
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		
		if (s.top() > m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
void Vector<T>::Del()
{

	T m = Min();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		
		if (!(t == m)) v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
void Vector<T>::Add()
{
	vector <T>v;
	T t;
	T el = Max();
	int i = 1;
	v.push_back(el);
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Srednee()
{
	
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;
	T sum = s.top();
	s.pop();

	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}

	s = copy_vector_to_stack(v);
	return sum / n;
}
template <class T>
void Vector<T>::Add_sred(T el)
{
	vector <T>v;
	T t;
	T e;
	int i = 1;
	while (!s.empty())
	{
		t = s.top();
		e = t + el;
		v.push_back(e);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}