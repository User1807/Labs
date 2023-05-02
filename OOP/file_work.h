#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)return -1;//ошибка открытия файла
	int n;
	Money m;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//ввод атрибутов объекта из стандартного потока
		stream << m << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Money m; int i = 0;
	while (stream >> m)
	{
		cout << m << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Money mm)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	int i = 0;
	Money m;
	while (stream >> m)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;
		//если номер объекта не равен k, то записываем его во вспомогательый файл
		if (m <= mm) temp << m;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных 
}

int add_file(const char* f_name, int n, Money mm)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Money m; int i = 0, l = 0;
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (i == n)
		{
			temp << mm;//записать в temp новую запись
			l++;
		}
		temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество добавленных
}

int add_end(const char* f_name, Money mm)
{
	fstream stream(f_name, ios::app);//открыть для добавления
	if (!stream)return -1;//ошибка открытия файла
	stream << mm; //записать новую запись
	return 1;
}

int change_file(const char* f_name, Money mm)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Money m; int i = 0, l = 0;
	char x;
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (m == mm)
		{
			temp << m+150;
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество измененных элементов
}