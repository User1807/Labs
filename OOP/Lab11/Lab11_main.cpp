#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<float>Vec;//���������� ��� ��� ������ � ��������
//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
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
float minimum(Vec v)
{
	float min = INT_MAX;
	//������� �������
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]<min)
			min = v[i];
	}
	return min;
}
void add_vector(Vec& v, float el, int pos)
{
	//��������� �� ����� pos ������� el
	v.insert(v.begin() + pos, el);
}
//���������� �������� ���������������
float srednee(Vec v)
{
	float s = 0;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
//������� �������� ������� �������� ���������������
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
//����� ������������� ��������
float maximum(Vec v)
{
	float max = INT_MIN;
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
	float m = maximum(v);
	cout << "Maximum: " << m << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * m;
}
//�������� �������
void main()
{
	try
	{
		vector<float> v;
		vector<float>::iterator vi = v.begin();
		//������������ �������
		int n;
		cout << "N? "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//���������� ������������
		float min = minimum(v);
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
		float sredn = srednee(v);
		del_vector(v, sredn);//������� �������� ������� ��������
		cout << "Srednee: "<< sredn << endl;
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