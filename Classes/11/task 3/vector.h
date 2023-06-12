#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class T> class Vector
{
	vector <T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	void Print();
	~Vector(void);
	T max();
	int min();
	T sred();
	void add(T);
	void del(int);
	void add_sred(T);
};
template <class T> Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void)
{
}

template <class T> Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a; v.push_back(a);
	}
	len = v.size();
}

template <class T> void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << "	";
	cout << endl;
}
template <class T>
T Vector<T>::max()
{
	T temp = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > temp) temp = v[i];
	}
	return temp;
}
template <class T>
int Vector<T>::min()
{
	T temp = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] < temp)
		{
			temp = v[i]; n = i;
		}
	}
	return n;
}
template <class T>
T Vector<T>::sred()
{
	T temp = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		temp = temp + v[i];
	}
	int n = v.size();
	return temp / n;
}
template <class T>
void Vector<T>::add(T a)
{
	v.insert(v.begin(), a);
}
template <class T>
void Vector<T>::del(int a)
{
	v.erase(v.begin() + a);
}
template <class T>
void Vector<T>::add_sred(T a)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + a;
	}
}