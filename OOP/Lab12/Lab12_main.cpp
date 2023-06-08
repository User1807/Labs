#include <iostream>
#include <map>
using namespace std;
typedef map<int, float>TMap;//определяем тип для работы со словарем
typedef TMap::iterator it;//итератор
//функция для формирования словаря
TMap make_map(int n)
{
	TMap m;//пустой словарь
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
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
	float m = (*i).second;//значение первого элемента
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
float srednee(TMap m)
{
	float s = 0;
	//перебор словаря
	for (int i = 0; i < m.size(); i++)
		s += m[i];
	int n = m.size();//количество элементов в словаре
	return s / n;
}

TMap deleteSr(TMap m, float sr)
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

float Max(TMap v)
{
	it i = v.begin();
	float m = (*i).second;//значение первого элемента
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
	float m = Max(v);//значение максимального элемента
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
	float sr = srednee(m);
	cout << endl << "srednee: " << sr << endl;
	m = deleteSr(m, sr);
	print_map(m);
	float max = Max(m);
	cout << "max= " << max << endl;
	multi(m);
	print_map(m);
}