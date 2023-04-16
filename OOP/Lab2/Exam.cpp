#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;

//����������� ��� ����������
Exam::Exam()
{
	fullName = "";
	subject = "";
	score = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}
//����������� � �����������
Exam::Exam(string n, string su, int sc)
{
	fullName = n;
	subject = su;
	score = sc;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}
//����������� �����������
Exam::Exam(const Exam& e)
{
	fullName = e.fullName;
	subject = e.subject;
	score = e.score;
	cout << "����������� ����������� ��� ������� " << this << endl;
}
//����������
Exam::~Exam()
{
	cout << "���������� ��� ������� " << this << endl;
}
//���������
string Exam::get_fullName()
{
	return fullName;
}
string Exam::get_subject()
{
	return subject;
}
int Exam::get_score()
{
	return score;
}
//������������
void Exam::set_fullName(string n)
{
	fullName = n;
}
void Exam::set_subject(string su)
{
	subject = su;
}
void Exam::set_score(int sc)
{
	score = sc;
}
//����� ��� ��������� ���������
void Exam::show()
{
	cout << "���: " << fullName << endl;
	cout << "�������: " << subject << endl;
	cout << "������: " << score << endl;
}