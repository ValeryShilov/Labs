#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next = nullptr;
};

class Iterator
{
	friend class List;
private:
	Node* elem;
public:
	Iterator() { elem = nullptr; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }
	//������� ������ � �������� � ������� n
	Iterator& operator + (const int& n) {
		for (int i = 0; i < n; i++) {
			if (elem == nullptr) {
				cout << "Error: end of file" << endl;
				exit(10);
			}
			elem = elem->next;
		}
		return *this;
	}
	//������������� �������� �������������
	int& operator *() const { return elem->data; }
};

class List
{
private:
	int size;
	Node* first;
	Node* last;
	Iterator beg;
	Iterator end;
public:
	List();
	List(int);
	List(const List&);
	~List();
	void push(int); //����� ��� ���������� ��������� � ����� ������
	void pop(); //����� ��� �������� ���������
	List& operator=(const List&);
	int& operator[] (int); //����� ��� ������� � �������� �� ������� 
	int operator()(); //����� ��� ����������� ������� ������
	friend List operator+(List&, List&); //����� ��� �������� ��������� ������� a[i]+b[i]
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
	Iterator f() { return beg; }
	Iterator l() { return end; }
};