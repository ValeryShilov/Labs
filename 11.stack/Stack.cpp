#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

int N; //временное количество элементов в стеке

Stack* peek;    // вершина стека


void Push(Stack* elem) // Добавление элемента в вершину стека
{
    if (N != 0)
        elem->next = peek;
    peek = elem;
    N++;
}

void Push_k(int k)
{
    int i = 0;

    Stack* node = new Stack;
    while (i < k)
    {
        node = new Stack;
        cin >> node->data;                    
        Push(node);
        i++;
    }
}

Stack* Pop()            // удаление из вершины стека
{
    Stack* delElem = peek;
    peek = peek->next;
    delElem->next = nullptr;
    N--;
    return delElem;
}

void Pop_k(int k)
{
    int i = 0;

    while (i < k)
    {
        Pop();
        i++;
    }
}

void create()
{
    cout << "Метод создания стека вызван" << endl;
    peek = nullptr;
    Stack* node = new Stack; 
    cout << "Введите элементы стека: ";
    cin >> node->data;
    node->next = nullptr;
    peek = node;

    int n = N;
    N = 1;
    for (int i = 1; i < n; i++)
    {
        node = new Stack;                      // Переход указателем на следующий элемент
        cin >> node->data;                    // Запись нового элемента
        node->next = nullptr;                       // Указатель на следующий элемент равен нулю, т. к. был записан последний элемент
        Push(node);
    }
    cout << "Стек заполнен" << endl;
}

void PrintConsole()
{
    Stack* first = peek;
    while (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
    }
    cout << endl;
}

fstream file;
string path = "Stack.txt";

void PrintFile()
{
    file.open(path, fstream::out); //открытие файла для записи
    if (!file.is_open())
        cout << "Ошибка открытия файла " << path << " для записи" << endl;
    else
    {
        Stack* first = peek;
        while (first != NULL)
        {
            file << first->data << endl;
            first = first->next;
        }

        cout << "Данные записаны в файл" << endl;
    }

    file.close();
}

void Delete()
{
    while (N != 0)
    {
        Stack* tmp = Pop();
        delete tmp;
    }
}

int r = 0;
void Recovery()
{
    file.open(path, fstream::in);
    if (!file.is_open())
        cout << "Ошибка открытия файла " << path << " для записи" << endl;
    else
    {

        Stack* node = new Stack;
        string tmp;
        getline(file, tmp);
        node->data = stoi(tmp);
        node->next = nullptr;
        peek = node;

        int i = 1; 
        N = 1;
        while (!file.eof())
        {
            if (i != 1)
            {
                node = new Stack;
                getline(file, tmp);
                if (tmp != "")
                {
                    node->data = stoi(tmp);      
                    node->next = nullptr;
                    Push(node);
                }
            }
            i++;
        }
        if (r == 0)
        {
            r++;
            PrintFile();
            Delete();
            Recovery();
        }
        r--;
        cout << "Стек восстановлен!" << endl;
    }

    file.close();
}

void menu() 
{
    cout << "~~~~~~~~ МЕНЮ ~~~~~~~~" << endl << endl;
    cout << "1.Создать стек" << endl;
    cout << "2.Добавить k элементов в стек" << endl;      
    cout << "3.Удалить k элементов из стека" << endl;        
    cout << "4.Вывод стека в консоль" << endl;
    cout << "5.Запись стека в файл" << endl;
    cout << "6. Уничтожение стека" << endl;
    cout << "7. Восстановление стека из файла" << endl;
    cout << "10. Выход" << endl;
    int c,k;
    cout << "Выберите пункт: "; cin >> c;
    switch (c)
    {
    case 1:
        system("cls");
        cout << "Введите количество элементов стека:  ";
        cin >> N;
        create();
        system("pause");
        system("cls");
        menu();

    case 2:
        system("cls");
        cout << "Введите количество элементов, которое вы хотите добавить в стек:  ";
        cin >> k;
        cout << "Введите элементs: ";
        Push_k(k);
        system("pause");
        system("cls");
        menu();


    case 3:
        system("cls");
        cout << "Введите количество элементов, которое вы хотите удалить из стека:  ";
        cin >> k;
        Pop_k(k);
        system("pause");
        system("cls");
        menu();

    case 4:
        system("cls");
        if (N == 0)
        {
            cout << "Элементы в стеке осутствуют!" << endl;
        }
        cout << "Cтек: ";
        PrintConsole();
        system("pause");
        system("cls");
        menu();

    case 5:
        system("cls");
        PrintFile();
        system("pause");
        menu();

    case 6:
        system("cls");
        Delete();
        if (N == 0) 
        {
            cout << "Cтек удален!" << endl;
            peek = nullptr;
        }
        system("pause");
        system("cls");
        menu();

    case 7:
        system("cls");
        Recovery();
        system("pause");
        system("cls");
        menu();
    case 10:
        exit(10);
    }
}



int main()
{
    system("chcp 1251>NULL");
    menu();
    return 0;
}



