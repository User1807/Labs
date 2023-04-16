#include <iostream>
#include "Exam.h"
#include <string>
using namespace std;

Exam make_exam()
{
	string surname;
	string name;
	string patronymic;
	string fullName;
	string subject;
	int score;
	cout << "Введите ФИО: ";
	cin >> surname >> name >> patronymic;
	fullName = surname + ' ' + name + ' ' + patronymic;
	cout << "Введите название предмета: ";
	cin >> subject;
	cout << "Введите оценку: ";
	cin >> score;
	Exam e(fullName, subject, score);
	return e;
}

void print_exam(Exam t)
{
	t.show();
}

int main()
{
	setlocale(LC_ALL, "ru");
	//конструктор без параметров
	Exam e1;
	e1.show();
	//коструктор с параметрами
	Exam e2("Ivanov Ivan Ivanovich", "Math", 4);
	e2.show();
	//конструктор копирования
	Exam e3 = e2;
	e3.set_fullName("Petrov Petr Petrovich");
	e3.set_subject("Informatics");
	e3.set_score(3);
	//конструктор копирования
	print_exam(e3);
	//конструктор копирования
	e1 = make_exam();
	cout << &e1 << ':' << endl;
	e1.show();
	return 0;
}