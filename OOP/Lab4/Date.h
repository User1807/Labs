#pragma once
#include "Triad.h"
//класс Date наследуется от класса Triad
class Date :
	public Triad
{
public:
	Date(void);//конструктор без параметров
	~Date(void);//деструктор
	Date(int, int, int);//конструктор с параметрами
	Date(const Date&);//конструктор копирования
	//модификаторы
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	//селекторы
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	Date& operator=(const Date&);//операция присваивания
	friend istream& operator>>(istream& in, Date& l);//операция ввода
	friend ostream& operator<<(ostream& out, const Date& l); //операция вывода
	//методы увеличения полей на 1
	Date& increaseFirst();
	Date& increaseSecond();
	Date& increaseThird();
	//метод увеличения даты на n дней
	Date& increaseDate(int);
protected:
	int year;
	int month;
	int day;
};