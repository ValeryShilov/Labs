#pragma once
#include "Object.h"

class Vector
{
public:
	Vector() { size = 0; cur = 0; beg = 0; };
	Vector(int);//конструктор с параметрами
public:
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	int operator()();//размер вектора
	virtual void HandleEvent(const TEvent&);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;
	int cur;
};