#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;

//конструктор без параметров
Exam::Exam()
{
	fullName = "";
	subject = "";
	score = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}
//конструктор с параметрами
Exam::Exam(string n, string su, int sc)
{
	fullName = n;
	subject = su;
	score = sc;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
//конструктор копирования
Exam::Exam(const Exam& e)
{
	fullName = e.fullName;
	subject = e.subject;
	score = e.score;
	cout << "Конструктор копирования для объекта " << this << endl;
}
//деструктор
Exam::~Exam()
{
	cout << "Деструктор для объекта " << this << endl;
}
//селекторы
string Exam::get_fullName()
{
	return fullName;
}
string Exam::get_subject()
{
	return subject;
}
int Exam::get_score()
{
	return score;
}
//модификаторы
void Exam::set_fullName(string n)
{
	fullName = n;
}
void Exam::set_subject(string su)
{
	subject = su;
}
void Exam::set_score(int sc)
{
	score = sc;
}
//метод для просмотра атрибутов
void Exam::show()
{
	cout << "ФИО: " << fullName << endl;
	cout << "Предмет: " << subject << endl;
	cout << "Оценка: " << score << endl;
}