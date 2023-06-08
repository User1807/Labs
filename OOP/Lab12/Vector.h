#pragma once
#include <vector>
#include <iostream>
#include <map>
using namespace std;

template<class T>
class Vector
{
	map <int, T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	void Print();
	~Vector(void);
	T minimum();
	void Add(T el, int pos);
	T srednee();
	void Del(T sredn);
	T Max();
	void Multiplication();
};

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void)
{
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;
	}
	len = v.size();
}

template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

template<class T>
T Vector<T>::minimum()
{
	T min = { INT_MAX, INT_MAX };
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	return min;
}

template<class T>
void Vector<T>::Add(T el, int pos)
{
	v[pos]=el;
}
template<class T>
T Vector<T>::srednee()
{
	Money s = { 0,0 };
	for (int i = 0; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

template<class T>
void Vector<T>::Del(T sredn)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > sredn)
		{
			v.erase(i);
			i--;
		}
	}
	if (v[v.size() - 1] > sredn)
		v.erase(v.size() - 1);
}

template<class T>
T Vector<T>::Max()
{
	T max = { -1, -1 };
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