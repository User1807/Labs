#include <iostream>
#include "fraction.h"
using namespace std;
//���������� ������ ��� ������������� ����� ���������
void fraction::Init(double F, double S)
{
	first = F; second = S;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "\nfirst? "; cin >> first;
	cout << "\nsecond? "; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Show()
{
	cout << "\nfirst= " << first;
	cout << "\nsecond= " << second;
	cout << "\n";
}
//����� ��� ���������� � �������
double fraction::hipotenuse()
{
	return pow(pow(first, 2)+pow(second, 2), 0.5);
}