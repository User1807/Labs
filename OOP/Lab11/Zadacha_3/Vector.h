#pragma once
#include <vector>
#include <iostream>
using namespace std;
//шаблон класса
template<class T>
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	void Print();//печать
	~Vector(void);//деструктор
	T minimum();//вычисление минимального элемента
	void Add(T el, int pos);//добавление элемента el на позицию pos
	T srednee();//найти среднее арифметическое
	void Del(T sredn);//удалить элементы большие среднего
	T Max();//найти номер максимального элемента
	void Multiplication();//умножение на минимальный
};

//конструктор без параметра
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//деструктор
template <class T>
Vector<T>::~Vector(void)
{
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}
//печать
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
//вычислить минимальный элемент
template<class T>
T Vector<T>::minimum()
{
	T min = {INT_MAX, INT_MAX};
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	return min;
}
//добавление элемента
template<class T>
void Vector<T>::Add(T el, int pos)
{
	v.insert(v.begin() + pos, el);
}
template<class T>
T Vector<T>::srednee()
{
	Money s = { 0,0 };
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}
//удалить элементы
template<class T>
void Vector<T>::Del(T sredn)
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
template<class T>
T Vector<T>::Max()
{
	T max = { -1, -1 };
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	return max;
}
template<class T>
void Vector<T>::Multiplication()
{
	T m = Max();
	cout << "Maximum: " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}