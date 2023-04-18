#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack
{
	struct Point
	{
		string data = "";
		Point* next = nullptr;
	};

	Point* head;
	Point* tail;
	size_t size;			
	bool isEmpty()
	{
		return size == 0;
	}						
	void output(Point* obj);					
	void push_op(Point* obj);					

public:
	Stack() : head(nullptr), size(0) {}
	Stack(int n);
	Stack(const Stack& stack);
	Stack& operator=(const Stack& stack);		
	~Stack();
	string top() const { return head->data; }	
	void Show();								
	void Push(string str);					
	string Pop();
	int operator()();
};