#include "List.h"
#include "Print.h"
#include "Magazin.h"
#include <iostream>
using namespace std;

//деструктор
List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//конструктор с параметрами
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void List::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
	else return;
}

void List::AddNew()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Car
	{
		Print* a = new (Print);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

void List::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int List::operator ()()
{
	return cur;
}

void List::Del()
{
	if (cur == 0)return;
	cur--;
}

void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}