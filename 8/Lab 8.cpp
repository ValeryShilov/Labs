#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
using namespace std;
char fname[20] = "file.bin\0";
char fname1[20] = "file1.bin\0";
struct Human {
	char fio[30];
	char adress[30];
	char number[20];
	int age;
};
void InputHuman(Human human) {
	FILE* fp;
	int n;
	fopen_s(&fp, fname, "ab");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	cout << "Введите данные о человеке " << endl; cin.getline(human.fio, 100);
	cout << "Введите ФИО: " << endl; cin.getline(human.fio, 100);
	cout << "Введите адрес: " << endl; cin.getline(human.adress, 100);
	cout << "Введите номер телефона: " << endl; cin >> human.number;
	cout << "Введите возраст: " << endl; cin >> human.age;
	fwrite(&human, sizeof(struct Human), 1, fp);
	if (fwrite == 0){
		cout << "Ошибка записи в файл\n";
		exit(2);
	}
	fclose(fp);
}
void PrintHuman() {  //вывод экзепляра структуры
	FILE* fp;
	Human* mas = new Human[100];
	Human* mas1 = new Human[100];
	int len = 0;
	fopen_s(&fp, fname, "rb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	int j = 0;
	while ((!feof(fp))) {
		fread(&mas1[j], sizeof(Human), 1, fp);
		len++;
	}
	fclose(fp);
	fopen_s(&fp, fname, "rb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	int i = 0;
	while (i < len-1) {
		fread(&mas[i], sizeof(Human), 1, fp);
		cout << i+1 << ".\n";
		cout << " ФИО: " << mas[i].fio << endl;
		cout << " Адрес: " << mas[i].adress << endl;
		cout << " Номер телефона: " << mas[i].number << endl;
		cout << " Возраст: " << mas[i].age << endl;
		i++;
		
	}
	fclose(fp);
	delete[] mas;
	delete[] mas1;
	cout << endl;
}
void deleteAll() {
	FILE* fp;
	fopen_s(&fp, fname, "wb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	fclose(fp);
}
void DeleteHum(int age) {
	FILE* fp;
	FILE* fp1;
	fopen_s(&fp, fname, "rb");
	fopen_s(&fp1, fname1, "wb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	if (fp1 == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	while (!feof(fp)) {
		Human h{};
		fread(&h, sizeof(Human), 1, fp);
		if (h.age != age) {
			fwrite(&h, sizeof(struct Human), 1, fp1);
			if (fwrite == 0) {
				cout << "Ошибка записи в файл\n";
				exit(2);
			}
		}
	}
	fclose(fp); fclose(fp1);
	fopen_s(&fp, fname, "wb");
	fopen_s(&fp1, fname1, "rb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	if (fp1 == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	while (!feof(fp1)) {
		Human h{};
		fread(&h, sizeof(Human), 1, fp1);
		if (h.age != age) {
			fwrite(&h, sizeof(struct Human), 1, fp);
			if (fwrite == 0) {
				cout << "Ошибка записи в файл\n";
				exit(2);
			}
		}
	}
	fclose(fp); fclose(fp1);
	
}
void AddHum(int n, Human h1) {
	FILE* fp;
	FILE* fp1;
	Human* mas1 = new Human[100];
	fopen_s(&fp, fname, "rb");
	fopen_s(&fp1, fname1, "wb");
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	if (fp1 == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	int i = 0;
	while (!feof(fp)) {
		Human h{};
		fread(&h, sizeof(Human), 1, fp);
		fwrite(&h, sizeof(struct Human), 1, fp1);
		if (fwrite == 0) {
			cout << "Ошибка записи в файл\n";
			exit(2);
		}
		if (i == n-1) {
			fwrite(&h1, sizeof(struct Human), 1, fp1);
			if (fwrite == 0) {
				cout << "Ошибка записи в файл\n";
				exit(2);
			}
		}
		i++;
	}
	fclose(fp); fclose(fp1);
	int len = 0;
	fopen_s(&fp1, fname, "rb");
	if (fp1 == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	int j = 0;
	while ((!feof(fp1))) {
		fread(&mas1[j], sizeof(Human), 1, fp1);
		len++;
	}
	fclose(fp1);
	fopen_s(&fp, fname, "wb");
	fopen_s(&fp1, fname1, "rb");
	int i1 = 0;
	while (i1 < len+1) {
		Human h{};
		fread(&h, sizeof(Human), 1, fp1);
		fwrite(&h, sizeof(struct Human), 1, fp);
		if (fwrite == 0) {
			cout << "Ошибка записи в файл\n";
			exit(2);
		}
		i1++;
	}
	if (fp == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	if (fp1 == NULL) {
		perror("\nОшибка открытия файла");
		exit(1);
	}
	fclose(fp); fclose(fp1);
	delete[] mas1;
}
void menu() {
	int n, c, age;
	Human a{};
	Human h1{};
	cout << "--------МЕНЮ--------" << endl;
	cout << "1.Вывести содержимое файла" << endl;
	cout << "2.Добавить человека" << endl;
	cout << "3.Удалить всё содержимое файла\n";
	cout << "4.Удалить элементы с заданным возрастом\n";
	cout << "5.Добавить элемент после заданного\n";
	cout << "10. Завершить работу\n" << endl;
	cout << "Выберите пункт: "; cin >> c;
	switch (c) {
	case 1: 
		system("cls");
		/*cout << "Введите сколько человек вывести\n";
		cin >> n;*/
		PrintHuman();
		system("pause");
		system("cls");
		menu();
	case 2:
		system("cls");
		InputHuman(a);
		system("pause");
		system("cls");
		menu();
	case 3:
		deleteAll();
		system("pause");
		system("cls");
		menu();
	case 4:
		system("cls");
		cout << "Введите возраст "; cin >> age;
		DeleteHum(age);
		DeleteHum(0);
		system("pause");
		system("cls");
		menu();
	case 5:
		system("cls");
		cout << "Введите номер элемента после которого добавить элемент: "; cin >> n;
		cout << "Введите данные о человеке " << endl; cin.getline(h1.fio, 100);
		cout << "Введите ФИО: " << endl; cin.getline(h1.fio, 100);
		cout << "Введите адрес: " << endl; cin.getline(h1.adress, 100);
		cout << "Введите номер телефона: " << endl; cin >> h1.number;
		cout << "Введите возраст: " << endl; cin >> h1.age;
		AddHum(n, h1);
		DeleteHum(0);
		system("pause");
		system("cls");
		menu();
	case 10: exit(10);
	default:
		break;
	}
}
int main()
{
	system("chcp 1251");
	system("cls");
	menu();
	return 0;
}
