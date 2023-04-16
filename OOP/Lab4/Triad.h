#pragma once
#include <string>
#include <iostream>
using namespace std;
class Triad
{
	//конструктор без параметров
public:
	Triad(void);
	//деструктор
	virtual ~Triad(void);
	//констрктор с параметрами
	Triad(int, int, int);
	//конструктор копирования
	Triad(const Triad&);
	//селекторы
	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }
	//модификаторы
	void setFirst(int);
	void setSecond(int);
	void setThird(int);
	//перегрузка операции присваивания
	Triad& operator=(const Triad&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Triad& c);
	friend ostream& operator<<(ostream& out, const Triad& c);
	//методы увеличения полей на 1
	Triad& increaseFirst();
	Triad& increaseSecond();
	Triad& increaseThird();
	//методы изменения полей
	void changeFirst(int);
	void changeSecond(int);
	void changeThird(int);
	//атрибуты
protected:
	int first;
	int second;
	int third;
};
