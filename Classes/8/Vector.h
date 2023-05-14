#pragma once
#include "Object.h"

class Vector
{
public:
	Vector() { size = 0; cur = 0; beg = 0; };
	Vector(int);//����������� � �����������
public:
	~Vector(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	int operator()();//������ �������
	virtual void HandleEvent(const TEvent&);
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;
	int cur;
};