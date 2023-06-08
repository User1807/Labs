#include <iostream>
#include <map>
#include "Money.h"
using namespace std;
typedef map<int, Money>TMap;//���������� ��� ��� ������ �� ��������
typedef TMap::iterator it;//��������
//������� ��� ������������ �������
TMap make_map(int n)
{
	TMap m;//������ �������
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(i, a));
	}
	return m;//���������� ������� ��� ��������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << " " << endl;
}
//����� ������������ ��������
int Min(TMap v)
{
	it i = v.begin();
	int nom = 0,//����� �������������
		k = 0;//������� ���������
	Money m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� max
}
//���������� �������� ���������������
Money srednee(TMap m)
{
	Money s = { 0,0 };
	//������� �������
	for (int i = 0; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();//���������� ��������� � �������
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
	Money m = (*i).second;//�������� ������� ��������
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;//��������
	}
	return m;//max
}
void multi(TMap& v)
{
	Money m = Max(v);//�������� ������������� ��������
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}

//�������� �������
void main()
{
	int n, pos;
	cout << "N? "; cin >> n;//���������� ���������
	TMap m = make_map(n);//������� �������
	print_map(m);//���������� �������
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