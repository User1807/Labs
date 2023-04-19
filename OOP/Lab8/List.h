#pragma once
#include "Object.h"
#include "Event.h"
class List
{
public:
	List(int);//конструктор с параметрами
	virtual void HandleEvent(const TEvent& e);
public:
	~List(void);//деструктор
	void Add(Object*);//добавление элемента
	void AddNew();
	void Del();
	void Show();
	int operator()();//размер
protected:
	Object** beg;//указатель на первый элемент
	int size;//размер
	int cur;//текущая позиция
};

