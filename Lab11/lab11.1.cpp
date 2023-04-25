#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;
const int MAXLINE = 255; // макс длина строки

struct Point
{
	int number;
	int key;
	Point* next;
};

struct List
{
	size_t size = 0;
	Point* head = NULL;
	Point* tail = NULL;
};

void printList(List* list)
{
	if (list->size == 0)
		cout << "List is empty" << endl;
	else
	{
 		Point* current = list->head;
		for (int i = 0; i < list->size; i++)
		{
			cout << current->number << ". " << current->key << endl;
			current = current->next;
		}
	}
	cout << endl;
}

List* createList(int size)
{
	List* list = new List;
	list->size = size;
	for (int i = 0; i < size; i++)
	{
		Point* current = new Point;
		current->key = rand() % 100 + 1;
		current->number = i + 1;
		current->next = NULL;

		if (list->head == NULL)
			list->head = list->tail = current;
		else
		{
			list->tail->next = current;
			list->tail = current;
		}
	}

	return list;
}

List* recreateList(int size, fstream& f)
{
	List* newList = createList(size);
	f.open("file.txt", fstream::in | fstream::out | fstream::app);
	int s, s1;
	Point* current = newList->head;
	for (int i = 0; i < size; i++)
	{
		f >> s;
		f >> s1;
		current->number = s;
		current->key = s1;
		current = current->next;
	}
	return newList;
}

int deleteList(List* list)
{
	int n = list->size;
	Point* temp;
	for (int i = 0; i < list->size; i++)
	{
		temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	list->size = 0;
	list->tail = nullptr;
	cout << "List is deleted" << endl;
	return n;
}

int addElement(List* list, int number, int key)
{
	Point* current = new Point;
	current->key = key;
	current->number = list->size + 1;
	current->next = NULL;
	list->tail->next = current;
	list->tail = current;

	current = list->head;

	while (current->number < number)
		current = current->next;

	list->size++;
	int temp, temp2;
	temp = current->key;
	current->key = key;
	temp2 = current->next->key;
	current = current->next;
	current->key = temp;
	while (current->number < list->size)
	{
		current = current->next;
		temp = current->key;
		current->key = temp2;
		temp2 = temp;
		if (current->number < list->size) temp = current->next->key;
	}

	cout << "Element was added" << endl << endl;
	return 0;
}

void writeInFile(fstream& f, List* list)
{
	Point* current = new Point;
	current = list->head;
	string s;
	for (int i = 0; i < list->size; i++)
	{
		f << current->number << endl;
		f << current->key << endl;
		current = current->next;
	}
}

void deleteElements(List* list, int num)
{
	Point* current = list->head;

	for (int i = 0; i < num; i++)
	{
		current = current->next;
	}
	list->tail = current;
	current = current->next;
	int tempSize = list->size - (list->size-num);
	for (int i = 0; i < tempSize; i++)
	{
		Point* tmp = current;
		current = current->next;
		delete tmp;
		list->size--;
	}
	cout << "Elements was deleted" << endl << endl;
}

int main()
{
	fstream f;
	f.open("file.txt", fstream::in | fstream::out | fstream::app);
	const int n = 10;
	int number, key, numberToDelete, listSize;
	List* list = createList(n);
	printList(list);
	Point* e = new Point;
	cout << "Enter number and key of the element you want to add" << endl;
	cin >> number >> key;
	addElement(list, number, key);
	printList(list);
	cout << "Enter number of elements to delete" << endl;
	cin >> numberToDelete;
	deleteElements(list, numberToDelete);
	printList(list);
	cout << endl;
	writeInFile(f, list);
	f.close();
	listSize = deleteList(list);
	printList(list);
	list = recreateList(listSize, f);
	f.close();
	printList(list);
	deleteList(list);
	return 0;
}