#include "Mnojestvo.h"
#include "Money.h"
#include <iostream>
using namespace std;
void main()
{
	cout << "Enter set of 5 values: " << endl;
	//инициализация, ввод и вывод значений вектора
	Mnojestvo<long>A(5, 0);
	cin >> A;
	cout << A << endl;
	//инициализация и вывод значений вектора
	Mnojestvo <long>B(10, 1);
	cout << B << endl;
	//операция присваивания
	B = A;
	cout << B << endl;
	A = { 8, 10 };
	//доступ по индексу
	cout << A[2] << endl;
	//получение длины вектора
	cout << "size= " << A() << endl;
	Mnojestvo<long>C(10, 0);
	//операция разности множеств
	C = B - A;
	cout << C << endl;
	Money m;
	cin >> m;
	cout << m;
	Money first;
	cout << "\nfirst: ";
	cin >> first;
	Money second;
	cout << "\nsecond: ";
	cin >> second;
	Money third;
	third = first - second;
	cout << "third: " << third;
	Mnojestvo<Money> D(5, m);
	cin >> D;
	cout << D << endl;
	Mnojestvo<Money> E(10, m);
	cout << E << endl;
	E = D;
	cout << E << endl;
	cout << D[2] << endl;
	cout << "size=" << D() << endl;
	Mnojestvo<Money> F(10, m);
	F = D - E;
	cout << F << endl;
}