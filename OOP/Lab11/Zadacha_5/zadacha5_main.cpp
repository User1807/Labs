#include <D:\c++\Zadacha_3\Money.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Money>St;//����
typedef vector<Money>Vec;//������

St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//���� ����������
		s.push(m);//���������� �� � ����
	}
	return s;//������� ���� ��� ��������� �������
}

//�������� ���� � ������
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������ ������� �� ������ �����
		v.push_back(s.top());
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
}
//�������� ������ � ����
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}

void print_stack(St s)
{
	//�������� ���� � ������
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.top() << endl;//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}

Money minimum(St s)
{
	Vec v = copy_stack_to_vector(s);
	Money min = s.top();
	s.pop();
	//������� �������
	while (!s.empty())//���� ���� �� ������
	{
		if (s.top()<min)
		{
			min = s.top();
		}
		s.pop();
	}
	s = copy_vector_to_stack(v);//����������� ������ � ����
	return min;
}
void Add_to_stack(St& s, Money el, int pos)
{
	Vec v;
	Money t;
	int i = 1;//����� �������� � �����
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� �������
		//���� ����� ����� ������ �������, �� ������ �������� ������� 
		if (i == pos)v.push_back(el);//�������� ����� ������� � ������
		v.push_back(t);//�������� ������� �� ����� � ������
		s.pop();//������� ������� �� �����
		i++;
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
Money Srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	int n = 1;
	Money sum = s.top();//��������� ����������� �����
	s.pop();//������� ������ ������� �� �������
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//�������� � ����� ������� �� ������� �����
		s.pop();//������� �������
		n++;
	}
	s = copy_vector_to_stack(v);//����������� ������ � ����
	return sum / n; //������� ������� ��������������
}
void Delete_from_stack(St& s)
{
	Money m = Srednee(s);//������� �������
	Vec v;
	Money t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� ������� �����
		//���� �� �� ����� �������������, ������� ������� � ������
		if (t < m)v.push_back(t);
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

//����� ������������� ��������
Money Max(St s)
{
	Money m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
//��������� �� ������������
void Multiplication(St& s)
{
	Money m = Max(s);//������� ������������ �������
	Vec v;
	Money t;
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� �������
			v.push_back(t * m);//�������� t �� ����������� � ��������� � ������
		s.pop();//������� ������� �� �������
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

void main()
{
	Money t;
	St s;
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);//������� ����
	print_stack(s);//������ �����
	t = minimum(s);//��������� �����������
	cout << "Minimum = " << minimum(s) << endl;
	cout << "Add minimum: " << endl;
	cout << "pos?";
	int pos;
	cin >> pos;//������ ������� ��� ����������
	Add_to_stack(s, t, pos);//���������� ��������
	print_stack(s);//������ �����
	Delete_from_stack(s);
	print_stack(s);//������ �����
	Multiplication(s);
	print_stack(s);//������ �����
}