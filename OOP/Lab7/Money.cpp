#include "Money.h"
Money::Money(void)
{
	rubles = pennies = 0;
}
Money::Money(int R, int P)
{
	rubles = R; 
	pennies = P;
}
Money::Money(const Money& m)
{
	rubles = m.rubles;
	pennies = m.pennies;
}
Money& Money::operator =(const Money& m)
{
	rubles = m.rubles;
	pennies = m.pennies;
	return*this;
}
ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rubles << "," << m.pennies;
	return out;
}
istream& operator>>(istream& in, Money& m)
{
	cout << "\nrubles? "; in >> m.rubles;
	cout << "\npennies? "; in >> m.pennies;
	return in;
}

Money Money::operator-(Money a)
{
	int first = rubles * 100 + pennies;
	int second = a.rubles * 100 + a.pennies;
	first -= second;
	Money temp(first / 100, first % 100);
	return temp;
}