#include "Print.h"
#include <iostream>
#include <string>
using namespace std;
//����������� ��� ����������
Print::Print(void)
{
	name = "";
	author = "";
}
//����������
Print::~Print(void)
{
}
//���������� � �����������
Print::Print(string N, string A)
{
	name = N;
	author = A;
}
//����������� �����������
Print::Print(const Print& print)
{
	name = print.name;
	author = print.author;
}
//���������
void Print::setAuthor(string A)
{
	author = A;
}
void Print::setName(string M)
{
	name = M;
}
//�������� ������������
Print& Print::operator=(const Print& p)
{
	if (&p == this)return *this;
	name = p.name;
	author = p.author;
	return *this;
}
//����� ��� ��������� ���������
void Print::Show()
{
	cout << "\nNAME : " << name;
	cout << "\nAUTHOR : " << author;
	cout << "\n";
}
//����� ��� ����� �������� ���������
void Print::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAuthor: "; cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//�������-���������
	{
		switch (e.command)
		{
		case cmGet:cout << "Name= " << getName() << endl;
			break;
		}
	}
}