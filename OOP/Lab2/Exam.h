#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//��������
	string fullName;
	string subject;
	int score;
public:
	Exam();//����������� ��� ����������
	Exam(string, string, int);//����������� � �����������
	Exam(const Exam&);//����������� �����������
	~Exam();//����������
	string get_fullName();//��������
	void set_fullName(string);//�����������
	string get_subject();//��������
	void set_subject(string); //�����������
	int get_score();//��������
	void set_score(int); //�����������
	void show();//�������� ���������
};