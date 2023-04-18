﻿#include <iostream>
#include "Mnojestvo.h"
using namespace std;

void main()
{
	Mnojestvo a(5);//создали вектор из 5 элементов, заполненный нулями
	cout << a << "\n";//вывели значения элементов вектора
	cin >> a;//ввели с клавиатуры значения элементов вектора
	cout << a << "\n";//вывели значения элементов вектора
	a[2] = 100;//используя операцию [] присвоили новое значение элементу 
	cout << a << "\n";//вывели значения элементов вектора
	Mnojestvo b(10);//создали вектор b из 10 элементов, заполненный нулями
	cout << b << "\n";//вывели значения элементов вектора
	b = a;//присвоили вектору b значения вектора a
	cout << b << "\n";//вывели значения элементов вектора
	Mnojestvo c(10); //создали вектор c из 10 элементов, заполненный нулями
	c = b + 100;//Увеличили значения вектора b на 100 и присвоили вектору c
	cout << c << "\n";//вывели значения элементов вектора c
	cout << "\nthe length of a=" << a() << endl;//вывели длину вектора a
	//разыменовываем значение, которое возвращает a.first() и выводим его 
	cout << *(a.first()) << endl;
	//переменную типа Iterator устанавливаем на первый элемент вектора а с
	//помощью метода first
	Iterator i = a.first();
	//оперция инкремент
	++i;
	//разыменовываеи итератор и выводи его значение
	cout << *i << endl;
	//выводим значения элеменов вектора с помощью итератора
	for (i = a.first(); i != a.last(); ++i)cout << *i << endl;
}
