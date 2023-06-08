#pragma once
#include <iostream>
using namespace std;
class Money
{
	long rubles;
	int pennies;
public:
	Money() { rubles = 0; pennies = 0; };
	Money(int r, int p) { rubles = r; pennies = p; }
	Money(const Money& m) { rubles = m.rubles; pennies = m.pennies; }
	~Money() {}
	int get_ruble() { return rubles; }
	int get_penny() { return pennies; }
	void set_ruble(int r) { rubles = r; }
	void set_penny(int p) { pennies = p; }
	Money& operator=(const Money&);
	Money& operator--();
	Money operator--(int);
	bool operator==(const Money&);
	bool operator!=(const Money&);
	Money operator+(const Money&);
	Money operator*(const Money&);
	Money operator/(const int&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
};