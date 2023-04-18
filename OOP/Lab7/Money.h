#include <iostream>
using namespace std;
class Money
{
public:
	Money(void);
	Money(int, int);
	Money(const Money&);
	Money& operator=(const Money&);
	//перегруженные операции ввода-вывода
	friend ostream& operator<< (ostream& out, const Money&);
	friend istream& operator>> (istream& in, Money&);
	Money operator-(Money a);
public:
	virtual ~Money(void) {};
private:
	long rubles; 
	int pennies;
};