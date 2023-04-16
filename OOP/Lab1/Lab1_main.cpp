#include <iostream>
#include "fraction.h"
using namespace std;
fraction make_fraction(double F, double S)
{
	fraction t;//создали временную переменную 
	t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции
	return t;//вернули значение переменной t
}

int main()
{
	//определение переменных А и В
	fraction A;
	fraction B;
	A.Init(3.0, 4.0);//инициализация переменной А
	B.Read();//ввод полей переменных В
	A.Show();//вывод значений полей переменной А
	B.Show();//вывод значений полей переменной В
	//вывод значения степени, вычисленного с помощью функции Power() 
	cout << "A.Hipotenuse(" << A.first << "," << A.second << ")=" << A.hipotenuse() << endl;
	cout << "B.Hipotenuse(" << B.first << "," << B.second << ")=" << B.hipotenuse() << endl;
	//указатели
	fraction* X = new fraction;//выделение памяти под динамическую переменную
	X->Init(2.0, 5);//инициализация
	X->Show();//вывод значений полей
	X->hipotenuse();//вычисление степени
	cout << "X.Hipotenuse(" << X->first << "," << X->second << ")=" << X->hipotenuse() << endl;
	//массивы
	fraction mas[3];//определение массива
	for (int i = 0; i < 3; i++)
		mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		mas[i].Show(); //вывод значений полей
	for (int i = 0; i < 3; i++)
	{
		mas[i].hipotenuse(); //вычисление степени
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].hipotenuse() << endl;
	}
	//динамические масивы
	fraction* p_mas = new fraction[3];//выделение памяти
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//вывод значений полей
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].hipotenuse();//вычисление степени
		cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].hipotenuse() << endl;
	}
	//вызов функции make_fraction()
	double y; int z;
	cout << "first? "; cin >> y;
	cout << "second? "; cin >> z;
	cout << endl;
	//переменная F формируется с помощью функции make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
	return 0;
}

