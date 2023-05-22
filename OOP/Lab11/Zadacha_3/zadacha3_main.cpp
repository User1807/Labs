//полный путь к файлу Time.h
#include <D:\c++\Zadacha_3\Money.h>
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector<Money>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	Money min = vec.minimum();//минимальное
	cout << "Minimum = " << min << endl;
	cout << "pos? ";
	int p;
	cin >> p;//ввести позицию для добавления
	vec.Add(min, p);//добавить элемент в вектор
	vec.Print();//печать вектора
	Money sredn = vec.srednee();//найти среднее арифметическое
	cout << "Srednee: " << sredn << endl;
	vec.Del(sredn);//удаление
	vec.Print();//печать
	vec.Multiplication();//деление
	vec.Print();//печать
}