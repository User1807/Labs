#include <iostream>
#include "Mnojestvo.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	Mnojestvo a(5);
	cout << a << "\n";
	cout << "Введите значения множества A: " << endl;
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	cout << "Множество B: " << endl;
	Mnojestvo b(10);
	cout << b << "\n";
	b = a;
	cout << b << "\n";
	Mnojestvo c(5);
	cout << "Введите значения множества C: " << endl;
	cin >> c;
	Mnojestvo d(10); 
	d = b - c;
	cout << "Разница множеств B и C:" << d << "\n";
	cout << "Размер множества A = " << a() << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); ++i)cout << *i << endl;
}
