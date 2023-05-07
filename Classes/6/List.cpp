#include "List.h"

List::List()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

List::List(int s)
{
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 1; i <= s; i++)
	{
		Node* new_node = new Node;
		new_node->data = i;
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
	beg.elem = first;
	end.elem = nullptr;
}

List::List(const List& temp)
{
	size = 0;
	first = nullptr;
	last = nullptr;
	Node* current = temp.first;
	while (current != nullptr) {
		Node* newNode = new Node();
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
	beg = temp.beg;
	end = temp.end;
}

List::~List()
{
	Node* current = first;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}
void List::push(int n)
{
	Node* new_node = new Node;
	new_node->data = n;
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

void List::pop()
{
	int n;
	Node* current;
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
		for (int i = 0; i < n-2; i++)
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
	Node* temp = current->next;
	int i = 0;
	while (temp)
	{
		if (i == n-2)
		{
			current->next = temp->next;
			delete temp;
			size--;
			return;
		}
		current = temp;
		temp=  temp->next;
		i++;
	}
}

ostream& operator<<(ostream& out, const List& temp)
{
	cout << "Содержимое списка" << endl;
	Node* current = temp.first;
	for (int i = 0; i < temp.size; i++)
	{
		out << current->data << " ";
		current = current->next;
	}
	return out;
}

istream& operator>>(istream& in, List& temp)
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
List& List::operator=(const List& temp)
{
	size = 0;
	first = nullptr;
	last = nullptr;
	Node* current = temp.first;
	while (current != nullptr) {
		Node* newNode = new Node();
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
	beg = temp.beg;
	end = temp.end;
	return *this;
}

int& List::operator[](int n)
{
	Node* current = first;
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

int List::operator()()
{
	return size;
}

List operator+(List& one, List& two)
{
	if (one.size != two.size)
	{
		cout << "Ошибка, размеры списков не равны" << endl;
		exit(6);
	}
	Node* current1 = one.first;
	Node* current2 = two.first;
	List result;
	Node* current3 = result.first;
	for (int i = 0; i < one.size; i++)
	{
		int summ = current1->data + current2->data;
		result.push(summ);
		current1 = current1->next;
		current2 = current2->next;
	}
	return result;
}