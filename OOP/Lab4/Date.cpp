#include "Date.h"
//конструктор без параметров
Date::Date(void) :Triad()
{
	day = 0;
	year = 0;
	month = 0;
}
//дестрктор
Date::~Date(void)
{
}
//конструктор с параметрами
Date::Date(int D, int M, int Y) :Triad(D, M, Y)
{
	day = D;
	month = M;
	year = Y;
}
//конструктор копирования
Date::Date(const Date& D)
{
	day = D.day;
	month = D.month;
	year = D.year;
}
//модификаторы
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

//оперция присваивания
Date& Date::operator=(const Date& d)
{
	if (&d == this)return *this;
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Date& d)
{
	cout << "\nDay: "; in >> d.day;
	cout << "\nMonth: "; in >> d.month;
	cout << "\nYear: "; in >> d.year;
	return in;
}
//операция вывода
ostream& operator<<(ostream& out, const Date& d)
{
	out << "\nDAY : " << d.day;
	out << "\nMONTH : " << d.month;
	out << "\nYEAR : " << d.year;
	out << "\n";
	return out;
}

//методы увеличения полей на 1
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

//метод увеличения даты на n дней
Date& Date::increaseDate(int n)
{
	day+=n;
	return *this;
}
