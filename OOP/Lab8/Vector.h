#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
	Vector(int);//����������� � �����������
	virtual void HandleEvent(const TEvent& e);
public:
	~Vector(void);//����������
	void Add(Object*);//���������� ��������
	void AddNew();
	void Del();
	void Show();
	int operator()();//������
protected:
	Object** beg;//��������� �� ������ �������
	int size;//������
	int cur;//������� �������
};

