#include "Triad.h"

//конструктор без параметров
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
//деструктор
Triad::~Triad(void)
{
}
//конструктор с параметрами
Triad::Triad(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}
//конструктор копирования
Triad::Triad(const Triad& car)
{
	first = car.first;
	second = car.second;
	third = car.third;
}
//модификаторы
void Triad::setFirst(int F)
{
	first = F;
}
void Triad::setSecond(int S)
{
	second = S;
}
void Triad::setThird(int T)
{
	third = T;
}
//перегрузка операции присваивания
Triad& Triad::operator=(const Triad& t)
{
	if (&t == this)return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}

//методы увеличения полей на 1
Triad& Triad::increaseFirst()
{
	first++;
	return *this;
}

Triad& Triad::increaseSecond()
{
	second++;
	return *this;
}

Triad& Triad::increaseThird()
{
	third++;
	return *this;
}

//методы изменения полей
void Triad::changeFirst(int F)
{
	first=F;
}

void Triad::changeSecond(int S)
{
	second=S;
}

void Triad::changeThird(int T)
{
	third=T;
}

//глобальная функция для ввода
istream& operator>>(istream& in, Triad& t)
{
	cout << "\nFirst: "; in >> t.first;
	cout << "\nSecond: "; in >> t.second;
	cout << "\nThird: "; in >> t.third;
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Triad& t)
{
	out << "\nFIRST : " << t.first;
	out << "\nSECOND : " << t.second;
	out << "\nTHIRD : " << t.third;
	out << "\n";
	return out;
}

void Triad::Show()
{
	cout << "\nFIRST : " << first;
	cout << "\nSECOND : " << second;
	cout << "\nTHIRD : " << third;
	cout << "\n";
}