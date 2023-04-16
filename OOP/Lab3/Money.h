#pragma once
#include <iostream>
using namespace std;
class Money
{
	long ruble;
	int penny;
public:
	Money() { ruble = 0; penny = 0; };
	Money(int r, int p) { ruble = r; penny = p; }
	Money(const Money& m) { ruble = m.ruble; penny = m.penny; }
	~Money() {}
	int get_ruble() { return ruble; }
	int get_penny() { return penny; }
	void set_ruble(int r) { ruble = r; }
	void set_penny(int p) { penny = p; }
	//перегруженные операции
	Money& operator=(const Money&);
	Money& operator--();
	Money operator--(int);//постфиксная операция
	bool operator==(const Money&);
	bool operator!=(const Money&);
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
};