#include <iostream>
#include "Triad.h"
#include "Date.h"
using namespace std;
// глобальные функции
void f1(Triad& c)
{
	c.setFirst(99999);
	cout << c;
}
Triad f2()
{
	Date d(10, 5, 2001);
	return d;
}
void main()
{
	//работа с классом Triad
	Triad a;
	cin >> a;
	cout << a;
	Triad b(1234, 567, 890);
	cout << b;
	a = b;
	cout << a;
	//работа с классом Date
	Date c;
	cin >> c;
	cout << c;
	//принцип подстановки
	f1(c);//передаем объект класса Date
	a = f2();//создаем в функции объект класса Date
	cout << a;
	a.changeSecond(12);
	cout << a;
	a.increaseThird();
	cout << a;
	c.increaseDate(3);
	cout << c;
}
