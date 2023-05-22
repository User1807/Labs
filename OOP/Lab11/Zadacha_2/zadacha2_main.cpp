#include <iostream>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>Vec;//���������� ��� ��� ������ � ��������
//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)
	{
		Money a = { rand() % 100, rand() % 100};
		v.push_back(a);//��������� � � ����� �������
	}
	return v;//���������� ������ ��� �������� ������ �������
}
//������� ��� ������ �������
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
//����� ������������ ��������
Money minimum(Vec v)
{
	Money min = {INT_MAX, INT_MAX};
	//������� �������
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	return min;
}
void add_vector(Vec& v, Money el, int pos)
{
	//��������� �� ����� pos ������� el
	v.insert(v.begin() + pos, el);
}
//���������� �������� ���������������
Money srednee(Vec v)
{
	Money s = { 0,0 };
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
//������� �������� ������� �������� ���������������
void del_vector(Vec& v, Money sredn)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > sredn)
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
	if (v[v.size()-1] > sredn)
		v.erase(v.begin() + v.size()-1);
}
//����� ������������� ��������
Money maximum(Vec v)
{
	Money max = {-1, -1};
	//������� �������
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	return max;
}
void multiplication(Vec& v)
{
	Money m = maximum(v);
	cout << "Maximum: " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}
//�������� �������
void main()
{
	try
	{
		vector<Money> v;
		vector<Money>::iterator vi = v.begin();
		//������������ �������
		int n;
		cout << "N? "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//���������� ������������
		Money min = minimum(v);
		//������� ��� �������
		cout << "pos? ";
		int pos;
		cin >> pos;
		//���������� ������, ���� ������� ��� ������� ������ ������� �������
		if (pos > v.size())throw 1;
		//����� ������� ��� ����������
		add_vector(v, min, pos);
		//������ �������
		print_vector(v);
		Money sredn = srednee(v);
		del_vector(v, sredn);//������� �������� ������� ��������
		cout << "Srednee: " << sredn << endl;
		print_vector(v);
		//������ ������� ��������� �� ����������� �������� �������
		multiplication(v);
		print_vector(v);
	}
	catch (int)//���� ��������� ������
	{
		cout << "error!";
	}
}