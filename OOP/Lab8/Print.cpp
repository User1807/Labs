#include "Print.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
Print::Print(void)
{
	name = "";
	author = "";
}
//деструктор
Print::~Print(void)
{
}
//констрктор с параметрами
Print::Print(string N, string A)
{
	name = N;
	author = A;
}
//конструктор копирования
Print::Print(const Print& print)
{
	name = print.name;
	author = print.author;
}
//селекторы
void Print::setAuthor(string A)
{
	author = A;
}
void Print::setName(string M)
{
	name = M;
}
//оператор присваивания
Print& Print::operator=(const Print& p)
{
	if (&p == this)return *this;
	name = p.name;
	author = p.author;
	return *this;
}
//метод для просмотра атрибутов
void Print::Show()
{
	cout << "\nNAME : " << name;
	cout << "\nAUTHOR : " << author;
	cout << "\n";
}
//метод для ввода значений атрибутов
void Print::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAuthor: "; cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "Name= " << getName() << endl;
			break;
		}
	}
}