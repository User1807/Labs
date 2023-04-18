#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Mnojestvo;//дружественный класс
public:
	Iterator() { elem = 0; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженные операции сравнения
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	//перегруженная операция инкремент 
	void operator++() { ++elem; };
	//перегруженная операция декремент
	void operator--() { --elem; }
	//перегруженная операция разыменования
	int& operator *() const { return*elem; }
private:
	int* elem;//указатель на элемент типа int
};

class Mnojestvo
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их 
	//значением k
	Mnojestvo(int s, int k = 0);
	//конструктор с параметрами
	Mnojestvo(const Mnojestvo& a);
	//деструктор
	~Mnojestvo();
	//оператор присваивания
	Mnojestvo& operator=(const Mnojestvo& a);
	//операция доступа по индексу
	int& operator[](int index);
	//операция для добавление константы
	Mnojestvo operator-(const Mnojestvo& a, const Mnojestvo& b);
	//операция, возвращающая длину вектора
	int operator()();
	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const Mnojestvo& a);
	friend istream& operator>>(istream& in, Mnojestvo& a);
	Iterator first() { return beg; }//возвращает указатель на первый элемент
	Iterator last() { return end; }//возвращает указатель на элемент следующий за 
	//последним
private:
	int size;
	int* data;
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
};