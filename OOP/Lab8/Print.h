#pragma once
#include "Object.h"
#include <string>
#include "Event.h"
using namespace std;

class Print :
	public Object
{
public:
	Print(void);//����������� ��� ����������
public:
	virtual ~Print(void);//����������
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������void Input();//������� ��� ����� �������� ���������
	void Input();
	Print(string, string);//����������� � �����������
	Print(const Print&);//����������� �����������
	//���������
	string getName() { return name; }
	string getAuthor() { return author; }
	//������������
	void setName(string);
	void setAuthor(string);
	Print& operator=(const Print&);//���������� �������� ������������
	void HandleEvent(const TEvent& e);
protected:
	string name;
	string author;
};