// Variant 12

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int collisions = 0;
string names[30] = { "Александр","Дмитрий","Максим","Сергей","Андрей","Алексей","Артём","Илья","Кирилл","Михаил","Никита","Матвей","Роман","Егор","Арсений","Иван","Денис","Евгений","Даниил","Тимофей","Владислав","Игорь","Владимир","Павел", "Руслан","Марк", "Константин","Тимур", "Олег","Ярослав"};
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
};

struct hash_table
{
	Human* arr;

	hash_table() { arr = new Human[0]; }

	hash_table(int size)
	{
		arr = new Human[size];
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
	double a = ((sqrt(5)-1)/2) * get_sum_of_fio(str);
	double c = size * (a - static_cast<int>(a));
	return static_cast<int>(c);
}

void hash_table::add(Human temp, const int size)
{
	int index = hash_func(temp.fio, size);
	int hash = index;
	if (arr[index].fio == "NULL")
	{
		arr[index] = temp;
		return;
	}
	else
	{
		while (index < size)
		{
			if (arr[index].fio == "NULL")
			{
				arr[index] = temp;
				return;
			}
			index++;
			collisions++;
		}
		if (index >= size)
		{
			index = 0;
			collisions++;
			while (index < hash)
			{
				if (arr[index].fio == "NULL")
				{
					arr[index] = temp;
					return;
				}
				index++;
				collisions++;
			}
		}
	}
}
void hash_table::pop(string fio_to_delete, const int size)
{
	int index = hash_func(fio_to_delete, size);
	if (arr[index].fio == fio_to_delete)
	{
		arr[index] = Human();
		cout << "Элемент удален" << endl;
		return;
	}
	else
	{
		while (index < size)
		{
			if (arr[index].fio == fio_to_delete)
			{
				arr[index] = Human();
				cout << "Элемент удален" << endl;
				return;
			}
			index++;
		}
		if (index >= size)
		{
			index = 0;
			while (index < size)
			{
				if (arr[index].fio == fio_to_delete)
				{
					arr[index] = Human();
					cout << "Элемент удален" << endl;
					return;
				}
				index++;
			}
		}
	}
	cout << "Элемент с удаляемым ФИО не найден" << endl;
}

void hash_table::find_index(string fio_to_find, const int size)
{
	int index = hash_func(fio_to_find, size);
	if (arr[index].fio == fio_to_find)
	{
		arr[index] = Human();
		cout << "Элемент с искомым фио под индексом: " << index << endl;
		return;
	}
	else
	{
		while (index < size)
		{
			if (arr[index].fio == fio_to_find)
			{
				cout << "Элемент с искомым фио под индексом: " << index << endl;
				return;
			}
			index++;
		}
		if (index >= size)
		{
			index = 0;
			while (index < size)
			{
				if (arr[index].fio == fio_to_find)
				{
					cout << "Элемент с искомым фио под индексом: " << index << endl;
					return;
				}
				index++;
			}
		}
	}
	cout << "Элемент с искомым ФИО не найден" << endl;
}


void show_hash_table(hash_table* table, const int size)
{
	for (int i = 0; i < size; i++)
	{
		show_human(table->arr[i]);
	}
}

void fill_hash_table(hash_table& table,int size)
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
		out << endl << table->arr[i].fio;
		out << endl << table->arr[i].pass_number;
		out << endl << table->arr[i].phone_number;
	}
	out.close();
}

void outfile(hash_table* table, int size)
{
	ifstream in;
	string str;
	in.open("file.txt");
	in.ignore(1,'\n');
	for (int i = 0; !in.eof(); i++)
	{
		getline(in, str);
		table->arr[i].fio = str;
		getline(in, str);
		table->arr[i].pass_number = str;
		getline(in, str);
		table->arr[i].phone_number = str;
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
		cout <<"Количество коллизий для " << size << " элементов = " << collisions << endl;
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