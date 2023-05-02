#include "Money.h"
Money::Money()
{
	rubles = 0;
	pennies = 0;
}
Money::Money(long R, int P)
{
	rubles = R; pennies = P;
}
Money::Money(const Money& m)
{
	rubles = m.rubles; pennies = m.pennies;
}
Money Money::operator =(const Money& m)
{
	if (&m == this) return *this;
	rubles = m.rubles; pennies = m.pennies;
	return*this;
}
Money::~Money()
{
}
Money& Money::operator--()
{
	int temp = rubles * 100 + pennies;
	temp--;
	rubles = temp / 100;
	pennies = temp % 100;
	return *this;
}
Money Money::operator+(int p)
{
	int temp = rubles * 100 + pennies;
	temp += p;
	rubles = temp / 100;
	pennies = temp % 100;
	return *this;
}
Money Money::operator --(int)
{
	int temp = rubles * 100 + pennies;
	temp--;
	Money t(rubles, pennies);
	rubles = temp / 100;
	pennies = temp % 100;
	return t;
}
bool Money::operator==(const Money& m)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = m.rubles * 100 + m.pennies;
	bool compare = (temp1 == temp2);
	return compare;
}
bool Money::operator<=(const Money& m)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = m.rubles * 100 + m.pennies;
	bool compare = (temp1 < temp2);
	return compare;
}
bool Money::operator!=(const Money& m)
{
	int temp1 = rubles * 100 + pennies;
	int temp2 = m.rubles * 100 + m.pennies;
	bool compare = (temp1 != temp2);
	return compare;
}
ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rubles << ',' << m.pennies << "\n";
	return out;
}
istream& operator>>(istream& in, Money& m)
{
	cout << "rubles? "; in >> m.rubles;
	cout << "pennies? "; in >> m.pennies;
	return in;
}

//дружественные функции для работы с файловыми потоками
fstream& operator>>(fstream& fin, Money& m)
{
	fin >> m.rubles;
	fin >> m.pennies;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rubles << "\n" << m.pennies << "\n";
	return fout;
}