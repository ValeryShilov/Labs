// Variant 12

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

int collisions = 0;
string names[30] = { "Александр","Дмитрий","Максим","Сергей","Андрей","Алексей","Артём","Илья","Кирилл","Михаил","Никита","Матвей","Роман","Егор","Арсений","Иван","Денис","Евгений","Даниил","Тимофей","Владислав","Игорь","Владимир","Павел", "Руслан","Марк", "Константин","Тимур", "Олег","Ярослав" };
string surnames[30] = { "Иванов","Смирнов","Кузнецов","Попов","Васильев","Петров","Соколов","Михайлов","Новиков","Федоров","Морозов","Волков","Алексеев","Лебедев","Семенов","Егоров","Павлов","Козлов","Степанов","Николаев","Орлов","Андреев","Макаров","Никитин","Захаров","Зайцев","Соловьев","Борисов","Яковлев","Григорьев" };
string patrinymic[30] = { "Александрович","Дмитриевич","Максимович","Сергеевич","Андреевич","Алексеевич","Артёмович","Ильич","Кирилович","Михайлович","Валериевич","Матвеевич","Романович","Германович","Арсеньевич","Иванович","Денисовч","Евгеньевич","Данилович","Тимофеевич","Владиславович","Игоревич","Владимирович","Павлович", "Русланович","Маркович", "Константинович","Тимурович", "Олегович","Ярославович" };
struct Human
{
	Human()
	{
		fio = "NULL";
		pass_number = "NULL";
		phone_number = "NULL";

	}
	string fio;
	string pass_number;
	string phone_number;

	bool operator ==(const Human& data) const // перегрузка оператора для функции remove в функции hash_table::pop
	{
		return fio == data.fio and pass_number == data.pass_number and phone_number == data.phone_number;
	}
};

struct hash_table
{
	list<Human>* arr;
	int size;

	hash_table(const int size)
	{
		this->size = size;
		arr = new list<Human>[this->size];
		for (int i = 0; i < size; i++)
			arr[i].push_front(Human());
	}
	~hash_table()
	{
		delete[] arr;
	}
	void add(Human temp, const int size);
	void pop(string fio_to_delete, const int size);
	void find_index(string fio, const int size);
};

string rando()
{
	if ((rand() % 10) > 5) return to_string(5);
	else return to_string(4);
}

string get_random_fio()
{
	return (surnames[rand() % 30] + "_" + names[rand() % 30] + "_" + patrinymic[rand() % 30]);
}

string get_random_pass_number()
{
	return (rando() + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + " " + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10));
}

string get_random_phone()
{
	return ("89" + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10));
}

Human create_random_human()
{
	Human temp;
	temp.fio = get_random_fio();
	temp.pass_number = get_random_pass_number();
	temp.phone_number = get_random_phone();
	return temp;
}

void show_human(Human temp)
{
	cout << "ФИО: " << temp.fio << endl;
	cout << "Номер паспорта: " << temp.pass_number << endl;
	cout << "Номер телефона: " << temp.phone_number << endl << endl;
}

void fill_arr_human(Human* arr, const int count)
{
	for (int i = 0; i < count; i++) {
		arr[i] = create_random_human();
	}
}

void print_arr_human(Human* arr, int size)
{
	for (int i = 0; i < size; i++) {
		show_human(arr[i]);
	}
}

int get_sum_of_fio(string str)
{
	int s = 0, i = 0;
	while (str[i] != '\0')
	{
		s += abs((int)str[i]);
		i++;
	}

	return s;
}

int hash_func(string str, const int size)
{
	double a = ((sqrt(5) - 1) / 2) * get_sum_of_fio(str);
	double c = size * (a - static_cast<int>(a));
	return static_cast<int>(c);
}



void hash_table::add(Human temp, const int size)
{
	int index = hash_func(temp.fio, size);
	int tmp = index;
	auto it = arr[index].begin();
	if ((*it).fio == "NULL")
	{
		*it = temp;
	}
	else
	{
		arr[index].push_back(temp);

	}
}
void hash_table::pop(string fio_to_delete, const int size)
{
	int index = hash_func(fio_to_delete, size);
	int tmp = index;
	auto it = arr[index].begin();
	if (arr[index].size() == 1)
	{

		if ((*it).fio == fio_to_delete)
		{
			*it = Human();
			return;
		}
		else
		{
			cout << "Удаление невозможно! Человека с таким фио не существует в таблице!" << endl;
			return;
		}
	}
	else
	{
		int i = 1;
		bool fl = false;
		while (i <= arr[index].size())
		{
			Human data = *it;
			if (data.fio == fio_to_delete)
			{
				arr[index].remove(data);
				fl = true;
				break;
			}
			i++;
			it++;
		}
		if (fl == false)
		{
			cout << "Удаление невозможно! Человека с таким фио не существует в таблице!" << endl;
		}
	}
}

void hash_table::find_index(string fio_to_find, const int size)
{
	int index = hash_func(fio_to_find, size);
	int tmp = index; 
	auto it = arr[index].begin();
	if (arr[index].size() == 1)
	{
		if ((*it).fio == fio_to_find)
		{
			cout << "Человек, с фио " << fio_to_find << " записан под индексом " << index << endl;
			return;
		}
		else
		{
			cout << "Человек с фио " << fio_to_find << " не занесён в таблицу!" << endl;
			return;
		}
	}
	else
	{
		int i = 1;
		bool fl = false;
		while (i <= arr[index].size())
		{
			if ((*it).fio == fio_to_find)
			{
				fl = true;
				cout << "Человек, с фио " << fio_to_find << " записан под индексом " << index << endl;
				return;

			}
			it++;
		}
		if (fl == false)
		{
			cout << "Человек с фио " << fio_to_find << " не занесён в таблицу!" << endl;
			return;
		}

	}
}


void show_hash_table(hash_table* table, const int size)
{
	
	for (int i = 0; i < size; i++)
	{
		auto it = table->arr[i].begin();
		for (int j = 0; j < table->arr[i].size(); j++) 
		{
			show_human(*it);
			it++;
		}
	}
}

void fill_hash_table(hash_table& table, int size)
{
	Human* arr = new Human[size];
	fill_arr_human(arr, size);
	for (int i = 0; i < size; i++)
	{
		table.add(arr[i], size);
	}
}


void infile(hash_table* table, int size)
{
	ofstream out;
	out.open("file.txt");
	for (int i = 0; i < size; i++)
	{
		auto it = table->arr[i].begin();
		if ((*it).fio != "NULL") 
		{
			for (int j = 0; j < table->arr[i].size(); j++)
			{
				out << endl << (*it).fio;
				out << endl << (*it).pass_number;
				out << endl << (*it).phone_number;
				it++;
			}
		}
	}
	out.close();
}

void outfile(hash_table* table, int size)
{
	ifstream in;
	string str;
	Human temp;
	in.open("file.txt");
	in.ignore(1, '\n');
	for (int i = 0; !in.eof(); i++)
	{
		getline(in, str);
		temp.fio = str;
		getline(in, str);
		temp.pass_number = str;
		getline(in, str);
		temp.phone_number = str;
		table->add(temp, size);
	}
}


void menu(hash_table& table, int size)
{
	int c;
	string str;
	cout << "-------------МЕНЮ-------------" << endl;
	cout << "1.Сгенерировать хеш-таблицу" << endl;
	cout << "2.Вывести хеш-таблицу" << endl;
	cout << "3.Найти элемент по ФИО" << endl;
	cout << "4.Удалить элемент по ФИО" << endl;
	cout << "5.Записать таблицу в файл" << endl;
	cout << "6.Восстановить таблицу из файла" << endl;
	cout << "10.Завершить работу" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		fill_hash_table(table, size);
		cout << "Количество коллизий для " << size << " элементов = " << collisions << endl;
		system("pause");
		system("cls");
		menu(table, size);
	case 2:
		system("cls");
		show_hash_table(&table, size);
		system("pause");
		system("cls");
		menu(table, size);
	case 3:
		system("cls");
		cout << "Введите ФИО для поиска" << endl;
		cin >> str;
		table.find_index(str, size);
		system("pause");
		system("cls");
		menu(table, size);
	case 4:
		system("cls");
		cout << "Введите ФИО для удаления" << endl;
		cin >> str;
		table.pop(str, size);
		system("pause");
		system("cls");
		menu(table, size);
	case 5:
		system("cls");
		infile(&table, size);
		system("pause");
		system("cls");
		menu(table, size);
	case 6:
		system("cls");
		outfile(&table, size);
		system("pause");
		system("cls");
		menu(table, size);
	case 10:
		exit(10);
	default:
		break;
	}
}
int main()
{
	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	int size;
	cout << "Введите количество элементов хеш-таблицы" << endl;
	cin >> size;
	hash_table table(size);
	menu(table, size);
	return 0;
}