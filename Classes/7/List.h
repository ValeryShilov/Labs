#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Node
{
public:
	type data;
	Node<type>* next;
	Node() : data(type()), next(nullptr) {}
	Node(const type& value)
	{
		data = value;
		next = nullptr;
	}
};

template <typename type>
class List
{
private:
	int size;
	Node<type>* first;
	Node<type>* last;
public:
	List();
	List(int, type);
	List(const List&);
	~List();

	void push(const type&); //Метод для добавления элементов в конец списка
	void pop(); //Метод для удаления элементов
	List<type>& operator=(const List&);
	type& operator[] (int); //Метод для доступа к элементу по индексу 
	int operator()(); //Метод для определения размера списка
	friend List<type> operator+(List&, List&); //Метод для сложения элементов списков a[i]+b[i]
	friend ostream& operator<<(ostream&, const List<type>&);
	friend istream& operator>>(istream&, List<type>&);
};