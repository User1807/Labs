#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//атрибуты
	string fullName;
	string subject;
	int score;
public:
	Exam();//конструктор без параметров
	Exam(string, string, int);//конструктор с параметрами
	Exam(const Exam&);//конструктор копирования
	~Exam();//деструктор
	string get_fullName();//селектор
	void set_fullName(string);//модификатор
	string get_subject();//селектор
	void set_subject(string); //модификатор
	int get_score();//селектор
	void set_score(int); //модификатор
	void show();//просмотр атрибутов
};