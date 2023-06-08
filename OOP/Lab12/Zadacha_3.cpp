#include "Money.h"
#include "Vector.h"
#include <map>
#include <iostream>
using namespace std;

void main()
{
	int n, pos;
	cout << "N? "; cin >> n;//количество элементов
	Vector<Money> v(n);
	v.Print();
	Money min = v.minimum();
	cout << "min= " << min << endl;
	cout << "pos? "; cin >> pos;
	v.Add(min, pos);
	v.Print();
	Money sr = v.srednee();
	cout << endl << "srednee: " << sr << endl;
	v.Del(sr);
	v.Print();
	Money max = v.Max();
	cout << "max= " << max << endl;
	v.Multiplication();
	v.Print();
}