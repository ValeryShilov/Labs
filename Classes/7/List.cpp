#include "List.h"
#include "Time.h"
#include <iostream>
using namespace std;

template <typename type>
List<type>::List()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template <typename type>
List<type>::List(int s,type d)
{
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 1; i <= s; i++)
	{
		Node<type>* new_node = new Node<type>;
		new_node->data = d;
		if (last == nullptr)
		{
			last = new_node;
			first = new_node;
		}
		else
		{
			last->next = new_node;
			last = new_node;
		}
	}
}

template <typename type>
List<type>::List(const List<type>& temp)
{
	size = 0;
	first = nullptr;
	last = nullptr;
	Node<type>* current = temp.first;
	while (current != nullptr) {
		Node<type>* newNode = new Node<type>();
		newNode->data = current->data;
		newNode->next = nullptr;
		if (last == nullptr) 
		{
			first = newNode;
			last = newNode;
		}
		else 
		{
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
		size++;
	}
}

template <typename type>
List<type>::~List()
{
	Node<type>* current = first;
	while (current != nullptr)
	{
		Node<type>* next = current->next;
		delete current;
		current = next;
	}
}

template <typename type>
void List<type>::push(const type& value)
{
	Node<type>* new_node = new Node<type>;
	new_node->data = value;
	new_node->next = nullptr;
	if (first == nullptr)
	{
		first = new_node;
		last = new_node;
		size++;
	}
	else
	{
		last->next = new_node;
		last = new_node;
		size++;
	}
}

template <typename type>
void List<type>::pop()
{
	int n;
	Node<type>* current;
	cout << "Введите номер удаляемого элемента" << endl;
	cin >> n;
	if (n == 1)
	{
		current = first->next;
		delete first;
		first = current;
		size--;
		return;
	}
	current = first;
	if (n == size)
	{
		for (int i = 0; i < n - 2; i++)
		{
			current = current->next;
		}
		delete last;
		current->next = nullptr;
		last = current;
		size--;
		return;
	}
	current = first;
	Node<type>* temp = current->next;
	int i = 0;
	while (temp)
	{
		if (i == n - 2)
		{
			current->next = temp->next;
			delete temp;
			size--;
			return;
		}
		current = temp;
		temp = temp->next;
		i++;
	}
}
template <typename type>
ostream& operator<<(ostream& out, const List<type>& temp)
{
	cout << "Содержимое списка" << endl;
	Node<type>* current = temp.first;
	for (int i = 0; i < temp.size; i++)
	{
		out << current->data << " ";
		current = current->next;
	}
	return out;
}
template <typename type>
istream& operator>>(istream& in, List<type>& temp)
{
	int cnt;
	cout << "Введите размер списка: "; cin >> cnt;
	cout << "Введите элементы списка" << endl;
	for (int i = 0; i < cnt; i++)
	{
		int value;
		in >> value;
		temp.push(value);
	}
	return in;
}

template <typename type>
List<type>& List<type>::operator=(const List<type>& temp)
{
	size = 0;
	first = nullptr;
	last = nullptr;
	Node<type>* current = temp.first;
	while (current != nullptr) {
		Node<type>* newNode = new Node<type>();
		newNode->data = current->data;
		newNode->next = nullptr;
		if (last == nullptr) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
		size++;
	}
	return *this;
}

template <typename type>
type& List<type>::operator[](int n)
{
	Node<type>* current = first;
	if (n > size || n < 0)
	{
		cout << "Заданный элемент отсутствует в списке" << endl;
		exit(5);
	}
	if (n == 0)
	{
		return first->data;
	}
	if (n == size)
	{
		return last->data;
	}
	for (int i = 1; i < n; i++)
	{
		current = current->next;
	}
	return current->data;

}

template <typename type>
int List<type>::operator()()
{
	return size;
}

template <typename type>
List<type> operator+(List<type>& one, List<type>& two)
{
	if (one.size != two.size)
	{
		cout << "Ошибка, размеры списков не равны" << endl;
		exit(6);
	}
	Node<type>* current1 = one.first;
	Node<type>* current2 = two.first;
	List<type> result;
	Node<type>* current3 = result.first;
	for (int i = 0; i < one.size; i++)
	{
		int summ = current1->data + current2->data;
		result.push(summ);
		current1 = current1->next;
		current2 = current2->next;
	}
	return result;
}