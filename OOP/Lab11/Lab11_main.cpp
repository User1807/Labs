#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<float>Vec;//определяем тип для работы с вектором
//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
		v.push_back(a);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
//поиск минимального элемента
float minimum(Vec v)
{
	float min = INT_MAX;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]<min)
			min = v[i];
	}
	return min;
}
void add_vector(Vec& v, float el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}
//вычисление среднего арифметического
float srednee(Vec v)
{
	float s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}
//удалить элементы большие среднего арифметического
void del_vector(Vec& v, float sredn)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > sredn)
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
	if (v[v.size() - 1] > sredn)
		v.erase(v.begin() + v.size() - 1);
}
//поиск максимального элемента
float maximum(Vec v)
{
	float max = INT_MIN;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	return max;
}
void multiplication(Vec& v)
{
	float m = maximum(v);
	cout << "Maximum: " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}
//основная функция
void main()
{
	try
	{
		vector<float> v;
		vector<float>::iterator vi = v.begin();
		//формирование вектора
		int n;
		cout << "N? "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//вычисление минимального
		float min = minimum(v);
		//позиция для вставки
		cout << "pos? ";
		int pos;
		cin >> pos;
		//генерируем ошибку, если позиция для вставки больше размера вектора
		if (pos > v.size())throw 1;
		//вызов функции для добавления
		add_vector(v, min, pos);
		//печать вектора
		print_vector(v);
		float sredn = srednee(v);
		del_vector(v, sredn);//удалить элементы большие среднего
		cout << "Srednee: "<< sredn << endl;
		print_vector(v);
		//каждый элемент разделить на минимальное значение вектора
		multiplication(v);
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}