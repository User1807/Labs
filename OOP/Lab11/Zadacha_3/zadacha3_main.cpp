//������ ���� � ����� Time.h
#include <D:\c++\Zadacha_3\Money.h>
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector<Money>vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	Money min = vec.minimum();//�����������
	cout << "Minimum = " << min << endl;
	cout << "pos? ";
	int p;
	cin >> p;//������ ������� ��� ����������
	vec.Add(min, p);//�������� ������� � ������
	vec.Print();//������ �������
	Money sredn = vec.srednee();//����� ������� ��������������
	cout << "Srednee: " << sredn << endl;
	vec.Del(sredn);//��������
	vec.Print();//������
	vec.Multiplication();//�������
	vec.Print();//������
}