#include "Date.h"
//����������� ��� ����������
Date::Date(void) :Triad()
{
	day = 0;
	year = 0;
	month = 0;
}
//���������
Date::~Date(void)
{
}
//����������� � �����������
Date::Date(int D, int M, int Y) :Triad(D, M, Y)
{
	day = D;
	month = M;
	year = Y;
}
//����������� �����������
Date::Date(const Date& D)
{
	day = D.day;
	month = D.month;
	year = D.year;
}
//������������
void Date::setDay(int D)
{
	day = D;
}

void Date::setMonth(int M)
{
	day = M;
}

void Date::setYear(int Y)
{
	day = Y;
}

//������� ������������
Date& Date::operator=(const Date& d)
{
	if (&d == this)return *this;
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}
//�������� �����
istream& operator>>(istream& in, Date& d)
{
	cout << "\nDay: "; in >> d.day;
	cout << "\nMonth: "; in >> d.month;
	cout << "\nYear: "; in >> d.year;
	return in;
}
//�������� ������
ostream& operator<<(ostream& out, const Date& d)
{
	out << "\nDAY : " << d.day;
	out << "\nMONTH : " << d.month;
	out << "\nYEAR : " << d.year;
	out << "\n";
	return out;
}

//������ ���������� ����� �� 1
Date& Date::increaseFirst()
{
	day++;
	return *this;
}

Date& Date::increaseSecond()
{
	month++;
	return *this;
}

Date& Date::increaseThird()
{
	year++;
	return *this;
}

//����� ���������� ���� �� n ����
Date& Date::increaseDate(int n)
{
	day+=n;
	return *this;
}
