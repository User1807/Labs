#pragma once
#include <string>
#include <iostream>
using namespace std;
class Triad
{
	//����������� ��� ����������
public:
	Triad(void);
	//����������
	virtual ~Triad(void);
	//���������� � �����������
	Triad(int, int, int);
	//����������� �����������
	Triad(const Triad&);
	//���������
	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }
	//������������
	void setFirst(int);
	void setSecond(int);
	void setThird(int);
	//���������� �������� ������������
	Triad& operator=(const Triad&);
	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Triad& c);
	friend ostream& operator<<(ostream& out, const Triad& c);
	//������ ���������� ����� �� 1
	Triad& increaseFirst();
	Triad& increaseSecond();
	Triad& increaseThird();
	//������ ��������� �����
	void changeFirst(int);
	void changeSecond(int);
	void changeThird(int);
	//��������
protected:
	int first;
	int second;
	int third;
};
