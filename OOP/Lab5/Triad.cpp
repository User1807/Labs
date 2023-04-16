#include "Triad.h"

//����������� ��� ����������
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
//����������
Triad::~Triad(void)
{
}
//����������� � �����������
Triad::Triad(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}
//����������� �����������
Triad::Triad(const Triad& car)
{
	first = car.first;
	second = car.second;
	third = car.third;
}
//������������
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
//���������� �������� ������������
Triad& Triad::operator=(const Triad& t)
{
	if (&t == this)return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}

//������ ���������� ����� �� 1
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

//������ ��������� �����
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

//���������� ������� ��� �����
istream& operator>>(istream& in, Triad& t)
{
	cout << "\nFirst: "; in >> t.first;
	cout << "\nSecond: "; in >> t.second;
	cout << "\nThird: "; in >> t.third;
	return in;
}
//���������� ������� ��� ������
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