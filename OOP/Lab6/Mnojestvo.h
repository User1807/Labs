#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Mnojestvo;//������������� �����
public:
	Iterator() { elem = 0; }//����������� ��� ����������
	Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������
	//������������� �������� ���������
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	//������������� �������� ��������� 
	void operator++() { ++elem; };
	//������������� �������� ���������
	void operator--() { --elem; }
	//������������� �������� �������������
	int& operator *() const { return*elem; }
private:
	int* elem;//��������� �� ������� ���� int
};

class Mnojestvo
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� �� 
	//��������� k
	Mnojestvo(int s, int k = 0);
	//����������� � �����������
	Mnojestvo(const Mnojestvo& a);
	//����������
	~Mnojestvo();
	//�������� ������������
	Mnojestvo& operator=(const Mnojestvo& a);
	//�������� ������� �� �������
	int& operator[](int index);
	//�������� ��� ���������� ���������
	Mnojestvo operator-(const Mnojestvo& a, const Mnojestvo& b);
	//��������, ������������ ����� �������
	int operator()();
	//������������� �������� �����-������
	friend ostream& operator<<(ostream& out, const Mnojestvo& a);
	friend istream& operator>>(istream& in, Mnojestvo& a);
	Iterator first() { return beg; }//���������� ��������� �� ������ �������
	Iterator last() { return end; }//���������� ��������� �� ������� ��������� �� 
	//���������
private:
	int size;
	int* data;
	Iterator beg;//��������� �� ������ ������� �������
	Iterator end;//��������� �� ������� ��������� �� ���������
};