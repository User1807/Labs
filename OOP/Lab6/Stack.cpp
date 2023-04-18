#include "Stack.h"

void Stack::push_op(Point* obj)
{
	if (obj == nullptr) return;
	push_op(obj->next);
	this->Push(obj->data);
}

Stack& Stack::operator=(const Stack& stack)
{
	while (this->Pop() != "");
	Point temp = *stack.head;
	push_op(&temp);

	return *this;
}
Stack::Stack(const Stack& stack)
{
	Point temp = *stack.head;
	push_op(&temp);
}
Stack::Stack(int n)
{
	if (n > 0)
	{
		string str;
		for (int i = 1; i <= n; i++)
		{
			cout << i << ". ";
			getline(cin, str);
			Push(str);
		}
	}
}

Stack::~Stack()
{
	while (Pop() != "");
}

void Stack::Push(string str)
{
	size++;
	Point* obj = new Point;
	obj->data = str;
	obj->next = head;
	head = obj;
}
string Stack::Pop()
{
	string result = "";
	if (!isEmpty())
	{
		result = head->data;
		Point* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	return result;
}

void Stack::output(Point* obj)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void Stack::Show()
{
	if (isEmpty()) cout << "Ñòåê ïóñò" << endl;
	else output(head);
}

int Stack::operator()()
{
	return size;
}