#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
	Vector(int);//конструктор с параметрами
	virtual void HandleEvent(const TEvent& e);
public:
	~Vector(void);//деструктор
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

