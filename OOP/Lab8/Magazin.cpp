#include <string>
#include "Magazin.h"
#include <iostream>
using namespace std;

Magazin::Magazin(void) :Print()
{
	name = "";
	author = "";
	pages = 0;
}
Magazin::~Magazin(void)
{
}
Magazin::Magazin(string N, string A, int P) : Print(N, A)
{
	name = N;
	author = A;
	pages = P;
}
Magazin::Magazin(const Magazin& M)
{
	name = M.name;
	author = M.author;
	pages = M.pages;
}
void Magazin::setPages(int P)
{
	pages = P;
}

Magazin& Magazin::operator=(const Magazin& m)
{
	if (&m == this)return *this;
	name = m.name;
	author = m.author;
	pages = m.pages;
	return *this;
}
void Magazin::Show()
{
	cout << "\nNAME : " << name;
	cout << "\nAUTHOR : " << author;
	cout << "\nPAGES : " << pages;
	cout << "\n";
}
void Magazin::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAuthor: "; cin >> author;
	cout << "\nPages: "; cin >> pages;
}