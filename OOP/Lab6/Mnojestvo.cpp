#include "Mnojestvo.h"
#include <iostream>
using namespace std;

Mnojestvo::Mnojestvo(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
//конструктор копирования
Mnojestvo::Mnojestvo(const Mnojestvo& m)
{
	size = m.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = m.data[i];
	beg = m.beg;
	end = m.end;
}
//деструктор
Mnojestvo::~Mnojestvo()
{
	delete[]data;
	data = 0;
}
//операция присваивания
Mnojestvo& Mnojestvo::operator=(const Mnojestvo& m)
{
	if (this == &m)return *this;
	size = m.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = m.data[i];
	beg = m.beg;
	end = m.end;
	return *this;
}
//операция доступа по индексу
int& Mnojestvo::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция для добавления константы
Mnojestvo Mnojestvo::operator-(const Mnojestvo& a, const Mnojestvo& b)//a-b
{
	return a - b;
}
//операция для получения длины вектора
int Mnojestvo::operator()()
{
	return size;
}
//операции для ввода-выода
ostream& operator<<(ostream& out, const Mnojestvo& m)
{
	for (int i = 0; i < m.size; ++i)
		out << m.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, Mnojestvo& m)
{
	for (int i = 0; i < m.size; ++i)
		in >> m.data[i];
	return in;
}