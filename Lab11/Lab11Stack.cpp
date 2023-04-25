#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h> 
#include <fstream>

using namespace std;
const int MAXLINE = 255;

struct Point
{
	int key;
	Point* next = nullptr;
};

struct Stack
{
	Point* head = nullptr;
	size_t size = 0;
};

bool stack_is_empty(Stack& stack)
{
	return stack.head == nullptr;
}
void output(Point* obj)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->key << endl;
}
void printStack(Stack& stack)
{
	if (stack.head == nullptr) cout << "Стек пуст" << endl;
	else output(stack.head);
}
void push(Stack& stack, int key)
{
	stack.size++;
	Point* obj = new Point;
	obj->key=key;
	obj->next = stack.head;
	stack.head = obj;
}
void pop(Stack& stack)
{
	if (stack.head != nullptr)
	{
		Point* temp = stack.head;
		stack.head = stack.head->next;
		delete temp;
		stack.size--;
	}
}
Stack* createStack(int size)
{
	Stack* stack = new Stack;
	if (size > 0 && stack->head == nullptr)
	{
		int key;
		cout << "Введите ключи " << size << " элементов стека: " << endl;
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			cin >> key;
			push(*stack, key);
		}
	}
	return stack;
}
void addElement(Stack& stack, int number, int k)
{
	int new_index = stack.size - number + 1;
	if (new_index < 0 || stack_is_empty(stack)) cout << "Введен неверный индекс/стек пуст" << endl;
	else
	{
		int key;
		Stack* stack2 = new Stack;
		for (int i = 1; i <= new_index; i++)
		{
			push(*stack2, stack.head->key);
			pop(stack);
		}
		cout << "Введите " << k << " элементов: " << endl;
		cin.get();
		for (int i = 1; i <= k; i++)
		{
			cin >> key;
			push(stack, key);
		}
		for (int i = 0; i < new_index; i++)
		{
			push(stack, stack2->head->key);
			pop(*stack2);
		}

	}
}
void deleteElement(Stack& stack, int key)
{
	int stack_size = stack.size;
	Stack* stack2 = createStack(0);
	for (int i = 1; i <= stack_size; i++)
	{
		if (stack.head->key != key)
		{
			push(*stack2, stack.head->key);
		}
		pop(stack);
	}
	cout << endl;
	int stack_size2 = stack2->size;
	for (int i = 1; i <= stack_size2; i++)
	{
		push(stack, stack2->head->key);
		pop(*stack2);
	}
}

void deleteStack(Stack& stack)
{
	Point* temp;
	while (stack.head != nullptr)
	{
		temp = stack.head->next;
		delete stack.head;
		stack.head = temp;
	}
	stack.size = 0;
	cout << "Стек удален!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fprintf(file, "%d\n", obj->key);
}
void writeInFile(Stack& stack, const char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	toFile_obj(stack.head, file);
	fclose(file);
}
void recreateStack(Stack& stack, const char* filename)
{
	FILE* file;
	int key;
	if ((file = fopen(filename, "rb")) == NULL)
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	while (!feof(file))
	{
		fscanf(file, "%d\n", &key);
		push(stack, key);
	}
	fclose(file);
}

int main()
{
	setlocale(LC_ALL, "ru");
	fstream f;
	f.open("file.txt", fstream::in | fstream::out | fstream::app);
	const int n = 10;
	int number, key, keyToDelete;
	Stack* stack = createStack(n);
	printStack(*stack);
	Point* e = new Point;
	cout << "Введите позицию и количество элементов для добавления" << endl;
	cin >> number >> key;
	addElement(*stack, number, key);
	printStack(*stack);
	cout << "Введите ключ элемента для удаления" << endl;
	cin >> keyToDelete;
	deleteElement(*stack, keyToDelete);
	printStack(*stack);
	cout << endl;
	writeInFile(*stack, "file.txt");
	f.close();
	deleteStack(*stack);
	printStack(*stack);
	recreateStack(*stack, "file.txt");
	f.close();
	printStack(*stack);
	deleteStack(*stack);
	return 0;
}