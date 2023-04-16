#include "Object.h"
#include "Triad.h"
#include "Date.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;
void main()
{
	Vector v(5);//вектор из 5 элементов
	Triad a;//объект класса Car
	cin >> a;
	Date b;// объект класса Lorry
	cin >> b;
	Object* p = &a;//ставим указатель на объект класса Car
	v.Add(p);//добавляем объект в вектор
	p = &b;//ставим указатель на объект класса Lorry
	v.Add(p); //добавляем объект в вектор
	cout << v;//вывод вектора
}