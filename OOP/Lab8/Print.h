#pragma once
#include "Object.h"
#include <string>
#include "Event.h"
using namespace std;

class Print :
	public Object
{
public:
	Print(void);//конструктор без параметров
public:
	virtual ~Print(void);//деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателяvoid Input();//функция для ввода значений атрибутов
	void Input();
	Print(string, string);//конструктор с параметрами
	Print(const Print&);//конструктор копирования
	//селекторы
	string getName() { return name; }
	string getAuthor() { return author; }
	//модификаторы
	void setName(string);
	void setAuthor(string);
	Print& operator=(const Print&);//перегрузка операции присваивания
	void HandleEvent(const TEvent& e);
protected:
	string name;
	string author;
};