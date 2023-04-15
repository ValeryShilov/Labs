#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int data;
	Node* p_next = nullptr;
	Node* p_prev = nullptr;
};
struct List
{
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
};

int am = 0;

void Init(List& list, int n)
{
	int d;
	if (list.head_node != nullptr)
	{
		cout << "Список уже создан" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		Node* new_node = new Node;
		cin >> d;
		new_node->data = d;
		if (list.head_node == nullptr) {
			list.head_node = new_node;
			list.tail_node = new_node;
		}
		else {
			Node* current_node = list.head_node;
			while (current_node->p_next != nullptr) {
				current_node = current_node->p_next;
			}
			new_node->p_prev = current_node;
			if (current_node->p_next != nullptr) {
				new_node->p_next = current_node->p_next;
				current_node->p_next->p_prev = new_node;
			}
			current_node->p_next = new_node;
			list.tail_node = new_node;

		}
	}
	 am = n;
}

void PushBack(List& list, int& data)
{
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == nullptr) {
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		Node* current_node = list.head_node;
		while (current_node->p_next != nullptr) {
			current_node = current_node->p_next;
		}
		new_node->p_prev = current_node;
		if (current_node->p_next != nullptr) {
			new_node->p_next = current_node->p_next;
			current_node->p_next->p_prev = new_node;
		}
		current_node->p_next = new_node;
		list.tail_node = new_node;
	}
	am++;
}

void AddNode(List& list, int n, int cnt)
{
	int num = 1;
	int el;
	Node* current_node = list.head_node;
	if (list.head_node != nullptr)
	{

		for (int i = 1; i <= n; i++) {
			current_node = current_node->p_next;
		}
		
		for (int j = 0; j < cnt; j++) {
			Node* new_node = new Node;
			Node* next = current_node;
			Node* prev = next->p_prev;
			cin >> el;
			new_node->data = el;
			new_node->p_next = next;
			new_node->p_prev = prev;
			prev->p_next = new_node;
			next->p_prev = new_node;
			prev = prev->p_prev;
			next = next->p_next;
			/*current_node->p_next = new_node;
			current_node->p_prev = new_node;*/
			//current_node = current_node->p_next;

		}
	}
	else cout << "Список пуст" << endl;
	am += n;
}

void DestroyList(List& list)
{
	if (list.head_node == nullptr)
	{
		cout << "Список пуст" << endl;
		return;
	}
	while (list.head_node != nullptr)
	{
		Node* remove = list.head_node;
		list.head_node = list.head_node->p_next;
		delete remove;
	}
	cout << "Список уничтожен" << endl;
	list.head_node = list.tail_node = nullptr;
	am = 0;
}

void DeleteEl(List& list, int n)
{

	int nd = 1;
	Node* remove = list.head_node;

	if (n == 1)
	{
		remove = list.head_node->p_next;
		remove->p_prev = nullptr;
		delete list.head_node;
		list.head_node = remove;
		cout << "Элемент под номером 1 удалён\n\n";
		am--;
		return;
	}
	if (n == am)
	{
		remove = list.tail_node->p_prev;
		remove->p_next = nullptr;
		delete list.tail_node;
		list.tail_node = remove;
		cout << "Элемент под номером " << am << " удален\n\n";
		am--;
		return;

	}
	if (remove == nullptr)
	{
		cout << "Список пуст" << endl;
		return;
	}

	Node* temp = remove->p_next;

	while (remove)
	{
		if (nd == n)
		{
			Node* left = remove->p_prev;
			Node* right = remove->p_next;
			left->p_next = right;
			right->p_prev = left;
			delete remove;
			cout << "Элемент под номером " << n << " удалён\n" << endl;
			am--;
			return;
		}
		remove = remove->p_next;
		nd++;
	}
}

void PrintList(List& list)
{
	Node* current_node = list.head_node;
	if (current_node != nullptr) {
		cout << "Содержимое списка:" << endl;
		while (current_node != nullptr) {
			cout << current_node->data << " ";
			current_node = current_node->p_next;
		}
		cout << endl;
	}
	else cout << "Список пуст" << endl;
	cout << endl;
}

void PrintListBack(List& list)
{
	Node* current_node = list.tail_node;
	if (current_node != nullptr) {
		cout << "Содержимое списка:" << endl;
		while (current_node != nullptr) {
			cout << current_node->data << " ";
			current_node = current_node->p_prev;
		}
		cout << endl;
	}
	else cout << "Список пуст" << endl;
	cout << endl;
}

void infile(List& list)
{
	ofstream f;
	f.open("file.txt");
	if (!f.is_open())
	{
		cout << "Ошибка при открытии файла\n";
		return;
	}
	Node* current_node = list.head_node;
	if (current_node == nullptr) {
		cout << "Список пуст";
		return;
	}
	while (current_node != nullptr)
	{
		f << current_node->data;
		current_node = current_node->p_next;
		if (current_node)
		{
			f << endl;
		}
	}
	cout << "Список записан в файл\n";
	f.close();
}

void recfile(List& list)
{
	int d;
	ifstream f;
	f.open("file.txt");
	if (!f.is_open()) {
		cout << "Ошибка при открытии файла\n";
		return;
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст\n";
		return;
	}
	if (list.head_node != nullptr)
	{
		cout << "Список не уничтожен" << endl;
		return;
	}
	for (int i = 0; !f.eof(); i++)
	{
		Node* new_node = new Node;
		f >> d;
		new_node->data = d;
		if (list.head_node == nullptr) {
			list.head_node = new_node;
			list.tail_node == new_node;
		}
		else {
			Node* current_node = list.head_node;
			while (current_node->p_next != nullptr) {
				current_node = current_node->p_next;
			}
			new_node->p_prev = current_node;
			if (current_node->p_next != nullptr) {
				new_node->p_next = current_node->p_next;
				current_node->p_next->p_prev = new_node;
			}
			current_node->p_next = new_node;
			list.tail_node = new_node;

		}
		am++;
	}
	cout << "Список восстановлен из файла\n";
	f.close();
}

void menu(List& list)
{
	int c, n, cnt;
	cout << "------------МЕНЮ------------" << endl;
	cout << "1.Вывести содержимое списка" << endl;
	cout << "11. Вывести содержимое списка с конца" << endl;
	cout << "2.Создать список" << endl;
	cout << "3.Добавить элемент в конец списка" << endl;
	cout << "4.Добавить k элементов после элемента с заданным номером" << endl;
	cout << "5.Удалить элемент с заданным номером" << endl;
	cout << "6.Уничтожить список" << endl;
	cout << "7.Записать список в файл" << endl;
	cout << "8.Восстановить список из файла" << endl;
	cout << "9.Вывести количество элементов в списке" << endl;
	cout << "0.Завершение работы" << endl << endl;
	cout << "Введите пункт меню: ";
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		PrintList(list);
		system("pause");
		system("cls");
		menu(list);
	case 11:
		system("cls");
		PrintListBack(list);
		system("pause");
		system("cls");
		menu(list);
	case 3:
		system("cls");
		cout << "Введите добавляемый элемент:" << endl;
		cin >> n;
		PushBack(list, n);
		system("pause");
		system("cls");
		menu(list);
	case 2:
		system("cls");
		cout << "Введите количество элементов" << endl;
		cin >> n;
		cout << "Введите элементы через Enter" << endl;
		Init(list, n);
		system("pause");
		system("cls");
		menu(list);
	case 4:
		system("cls");
		cout << "Введите номер элемента: ";
		cin >> n;
		cout << "Введите количество элементов: ";
		cin >> cnt;
		cout << "Введите элементы через Enter" << endl;
		AddNode(list, n, cnt);
		system("pause");
		system("cls");
		menu(list);
	case 5:
		system("cls");
		cout << "Введите номер удаляемого элемента" << endl;
		cin >> n;
		DeleteEl(list, n);
		system("pause");
		system("cls");
		menu(list);
	case 6:
		system("cls");
		DestroyList(list);
		system("pause");
		system("cls");
		menu(list);
	case 7:
		system("cls");
		infile(list);
		system("pause");
		system("cls");
		menu(list);
	case 8:
		system("cls");
		recfile(list);
		system("pause");
		system("cls");
		menu(list);
	case 9:
		system("cls");
		cout << "Количество элементов в списке " << am << endl;
		system("pause");
		system("cls");
		menu(list);
	case 0:
		exit(10);
	default:
		break;
	}
}
int main()
{
	setlocale(0, "");
	List list;
	menu(list);
	return 0;
}