#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;//������ �������� �����
	int n;
	Time p;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in); //������� ��� ������
	if (!stream) return -1; //������ �������� �����
	Time t; int i = 0;
	while (!stream.eof())
	{
		string str;
		getline(stream, str);
		//stream >> t;
		cout << str << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream) return -1;//������ �������� �����
	int i = 0; Time p;
	while (!stream.eof())//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof()) break;
		i++;
		string str;
		getline(stream, str);
		if (i != k) temp << str << endl;
	}
	//������� �����
	stream.close(); temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� ����������� 
}

int add_file(const char* f_name, int k, Time tt)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream) return -1;//������ �������� �����
	Time t; int i = 0, l = 0;
	while (!stream.eof())
	{
		if (stream.eof()) break;
		i++;
		string str;
		getline(stream, str);
		if (i == k)
		{
			temp << tt<< endl;//�������� � temp ����� ������
			l++;
		}
		temp << str << endl;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� �����������
}

int add_end(const char* f_name, Time t)
{
	fstream stream(f_name, ios::app);//������� ��� ����������
	if (!stream)return -1;//������ �������� �����
	stream << t; //�������� ����� ������
	return 1;
}

int change_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Time p; int i = 0, l = 0;
	char x;
	while (!stream.eof())
	{
		if (stream.eof())break;
		i++;
		string str;
		getline(stream, str);
		if (i == k)
		{
			cout << str << " - is changing... Continue[y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			temp << pp << endl;
			l++;
		}
		else temp << str << endl;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� ���������� ���������
}