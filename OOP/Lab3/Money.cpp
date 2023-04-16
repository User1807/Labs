#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money& Money::operator=(const Money& m)
{
	//проверка на самоприсваивание
	if (&m == this) return *this;
	ruble = m.ruble;
	penny = m.penny;
	return *this;
}
//перегрузка префиксной операции декремент
Money& Money::operator--()
{
	int temp = ruble * 100 + penny;
	temp--;
	ruble = temp / 100;
	penny = temp % 100;
	return *this;
}
//перегрузка постфиксной операции декремент
Money Money::operator --(int)
{
	int temp = ruble * 100 + penny;
	temp--;
	Money t(ruble, penny);
	ruble = temp / 100;
	penny = temp % 100;
	return t;
}
//перегрузка бинарной операции сравнения
bool Money::operator==(const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	bool compare = (temp1 == temp2);
	return compare;
}

bool Money::operator!=(const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	bool compare = (temp1 != temp2);
	return compare;
}

//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "rubles? "; in >> t.ruble;
	cout << "pennies? "; in >> t.penny;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.ruble << "," << t.penny);
}