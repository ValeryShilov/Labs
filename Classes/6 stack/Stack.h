#pragma once
#include <iostream>
using namespace std;

struct Node 
{
	Node* prev = nullptr, * next = nullptr;
	int data = 0;
};

class Stack 
{
private:
	int size;
	Node* head = nullptr, * tail = nullptr;
public:
	Stack();
	Stack(int s, int k = 0);
	Stack(const Stack&);
	~Stack();
	int front();
	void push(int data);
	void pop();
	bool empty();
	Stack& operator=(const Stack&);
	int& operator[](int index);
	int& operator()();
	Stack operator+(Stack&);
	friend ostream& operator <<(ostream&, const Stack&);
	friend istream& operator >>(istream&, const Stack&);
};