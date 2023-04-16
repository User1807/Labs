#include "Money.h"
#include <iostream>
using namespace std;
void main()
{
	Money a;//конструктор без параметров
	Money b; //конструктор без параметров
	bool compare;
	cin >> a;//ввод переменной
	cin >> b;//ввод переменной
	--a;//префиксная операция декремент
	cout << a << endl;//вывод переменной
	b--;//постфиксная операция декремент
	cout << b << endl;//вывод переменной
	compare = a == b;//сравнение
	cout << "a=" << a << endl; //вывод переменной
	cout << "b=" << b << endl; //вывод переменной
	cout << "c=" << compare << endl; //вывод переменной
	compare = a != b;//сравнение
	cout << "a=" << a << endl; //вывод переменной
	cout << "b=" << b << endl; //вывод переменной
	cout << "c=" << compare << endl; //вывод переменной
	a = b; //операция присваивания
	cout << "a=" << a << endl; //вывод переменной
	cout << "b=" << b << endl; //вывод переменной
	compare = a == b;//сравнение
	cout << "c=" << compare << endl; //вывод переменной
}