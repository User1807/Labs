#pragma once
#include "Object.h"
#include "Event.h"
class List
{
public:
	List(int);//����������� � �����������
	virtual void HandleEvent(const TEvent& e);
public:
	~List(void);//����������
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

