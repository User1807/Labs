#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money& Money::operator=(const Money& m)
{
	//проверка на самоприсваивание
	if (&m == this) return *this;
	rubles = m.rubles;
	pennies = m.pennies;
	return *this;
}
//перегрузка префиксной операции декремент
Money& Money::operator--()
{
	int temp = rubles * 100 + pennies;
	temp--;
	rubles = temp / 100;
	pennies = temp % 100;
	return *this;
}
//перегрузка постфиксной операции декремент
Money Money::operator --(int)
{
	int temp = rubles * 100 + pennies;
	temp--;
	Money t(rubles, pennies);
	rubles = temp / 100;
	pennies = temp % 100;
	return t;
}
//перегрузка бинарной операции сравнения
bool Money::operator==(const Money& t)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = t.rubles * 100 + t.pennies;
	bool compare = (temp1 == temp2);
	return compare;
}

bool Money::operator!=(const Money& t)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = t.rubles * 100 + t.pennies;
	bool compare = (temp1 != temp2);
	return compare;
}

//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "rubles? "; in >> t.rubles;
	cout << "pennies? "; in >> t.pennies;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rubles << "," << t.pennies);
}
bool Money::operator <(const Money& t)
{
	if (rubles < t.rubles)return true;
	if (rubles == t.rubles && pennies < t.pennies)return true;
	return false;
}
bool Money::operator >(const Money& t)
{
	if (rubles > t.rubles)return true;
	if (rubles == t.rubles && pennies > t.pennies)return true;
	return false;
}
Money Money::operator+(const Money& t)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = t.rubles * 100 + t.pennies;
	Money p;
	p.rubles = (temp1 + temp2) / 100;
	p.pennies = (temp1 + temp2) % 100;
	return p;
}
//перегрузка бинарной операции умножения
Money Money::operator*(const Money& t)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = t.rubles * 100 + t.pennies;
	Money p;
	p.rubles = (temp1 * temp2) / 10000;
	p.pennies = (temp1 * temp2) % 10000;
	return p;
}
Money Money::operator/(const int& t)
{
	int temp1 = rubles * 100 + pennies;
	Money p;
	p.rubles = (temp1 / t) / 100;
	p.pennies = (temp1 / t) % 100;
	return p;
}