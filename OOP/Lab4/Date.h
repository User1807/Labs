#pragma once
#include "Triad.h"
//����� Date ����������� �� ������ Triad
class Date :
	public Triad
{
public:
	Date(void);//����������� ��� ����������
	~Date(void);//����������
	Date(int, int, int);//����������� � �����������
	Date(const Date&);//����������� �����������
	//������������
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	//���������
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	Date& operator=(const Date&);//�������� ������������
	friend istream& operator>>(istream& in, Date& l);//�������� �����
	friend ostream& operator<<(ostream& out, const Date& l); //�������� ������
	//������ ���������� ����� �� 1
	Date& increaseFirst();
	Date& increaseSecond();
	Date& increaseThird();
	//����� ���������� ���� �� n ����
	Date& increaseDate(int);
protected:
	int year;
	int month;
	int day;
};