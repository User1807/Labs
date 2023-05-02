#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>
using namespace std;
class Money
{
public:
	Money();
	Money(long, int);
	Money(const Money&);
	~Money();
	Money operator =(const Money&);
	Money& operator--();
	Money operator--(int);
	Money operator+(int);
	bool operator==(const Money&);
	bool operator<=(const Money&);
	bool operator!=(const Money&);
	friend ostream& operator<<(ostream& out, const Money& m);
	friend istream& operator>>(istream& in, Money& m);
	friend fstream& operator>>(fstream& fin, Money& m);
	friend fstream& operator<<(fstream& fout, const Money& m);
private:
	long rubles;
	int pennies;
};