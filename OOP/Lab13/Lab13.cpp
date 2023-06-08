#include "Money.h"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<Money> TVector;
//формирование вектора
TVector make_vector(int n)
{
	Money a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//печать вектора
void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}

Money srednee(TVector v)
{
	Money s = {0, 0};
	for (int i = 0; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

typedef vector<Money> TVector;
Money s;

struct Greater_s //больше, чем s
{
	bool operator()(Money m)
	{
		if (m > s) return true; else return false;
	}
};

void multi(Money& m)
{
	m = m * s;
}

void main()
{
	int n, pos;
	cout << "N?";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);
	TVector::iterator i;
	//поставили итератор i на минимальный элемент
	i = min_element(v.begin(), v.end());
	Money min = *(i);
	cout << "min: " << min << endl;
	cout << "pos?"; cin >> pos;
	v[pos] = min;
	cout << "ZAMENA" << endl;
	print_vector(v);
	s = srednee(v);
	cout << "srednee: " << s << endl;
	Money m = { 0, 0 };
	replace_if(v.begin(), v.end(), Greater_s(), m);
	cout << "UDALENIE" << endl;
	print_vector(v);
	cout << "UMNOJENIE" << endl;
	i = max_element(v.begin(), v.end());
	s = *i;
	cout << "max: " << s << endl;
	//для каждого элемента вектора вызывается функция del
	for_each(v.begin(), v.end(), multi);
	print_vector(v);
}