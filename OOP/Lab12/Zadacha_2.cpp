#include <iostream>
#include <map>
#include "Money.h"
using namespace std;
typedef map<int, Money>TMap;//определяем тип для работы со словарем
typedef TMap::iterator it;//итератор
//функция для формирования словаря
TMap make_map(int n)
{
	TMap m;//пустой словарь
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//создаем пару и добавляем ее в словарь
		m.insert(make_pair(i, a));
	}
	return m;//возвращаем словарь как результат работы функции
}
//функция для печати словаря
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << " " << endl;
}
//поиск минимального элемента
int Min(TMap v)
{
	it i = v.begin();
	int nom = 0,//номер максимального
		k = 0;//счетчик элементов
	Money m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
//вычисление среднего арифметического
Money srednee(TMap m)
{
	Money s = { 0,0 };
	//перебор словаря
	for (int i = 0; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();//количество элементов в словаре
	return s / n;
}

TMap deleteSr(TMap m, Money sr)
{
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] > sr)
		{
			m.erase(i);
			i--;
		}
	}
	return m;
}

Money Max(TMap v)
{
	it i = v.begin();
	Money m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;//итератор
	}
	return m;//max
}
void multi(TMap& v)
{
	Money m = Max(v);//значение максимального элемента
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}

//основная функция
void main()
{
	int n, pos;
	cout << "N? "; cin >> n;//количество элементов
	TMap m = make_map(n);//создать словарь
	print_map(m);//напечатать словарь
	int min = Min(m);
	cout << "min= " << m[min] << " nom=" << min << endl;
	cout << "pos? "; cin >> pos;
	m[pos] = m[min];
	print_map(m);
	Money sr = srednee(m);
	cout << endl << "srednee: " << sr << endl;
	m = deleteSr(m, sr);
	print_map(m);
	Money max = Max(m);
	cout << "max= " << max << endl;
	multi(m);
	print_map(m);
}