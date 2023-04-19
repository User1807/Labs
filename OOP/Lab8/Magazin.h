#pragma once
#include <string>
#include "Print.h"
using namespace std;

class Magazin :
	public Print
{
public:
	Magazin(void);
public:
	~Magazin(void);
	void Show();
	void Input();
	Magazin(string, string, int);
	Magazin(const Magazin&);
	int getPages() { return pages; }
	void setPages(int);
	Magazin& operator=(const Magazin&);
protected:
	int pages;
};