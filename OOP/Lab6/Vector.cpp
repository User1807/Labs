#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
//����������� �����������
Vector::Vector(const Vector& m)
{
	size = m.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = m.data[i];
	beg = m.beg;
	end = m.end;
}
//����������
Vector::~Vector()
{
	delete[]data;
	data = 0;
}
//�������� ������������
Vector& Vector::operator=(const Vector& m)
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
//�������� ������� �� �������
int& Vector::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� �������� ��������
Vector Vector::operator-(const Vector& a)
{
	Vector temp(size);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] - a.data[i];
	return temp;
}
//�������� ��� ��������� ����� �������
int Vector::operator()()
{
	return size;
}
//�������� ��� �����-�����
ostream& operator<<(ostream& out, const Vector& m)
{
	for (int i = 0; i < m.size; ++i)
		out << m.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, Vector& m)
{
	for (int i = 0; i < m.size; ++i)
		in >> m.data[i];
	return in;
}