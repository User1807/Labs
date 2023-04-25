#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h> 

using namespace std;
const int MAXLINE = 255;

struct Point
{
	int key;
	Point* next = nullptr;
};
Point* head = nullptr;
Point* top = nullptr;
size_t qSize = 0;

void push(int key)
{
	if (qSize == 0)
	{
		head = new Point;
		head->key = key;
		top = head;
	}
	else
	{
		Point* obj = new Point;
		obj->key = key;
		top->next = obj;
		top = obj;
	}
	qSize++;

}
void pop()
{
	Point* temp = head;
	head = head->next;
	qSize--;
	delete temp;
}

void createQueue(int size)
{
	if (size > 0 && qSize == 0)
	{
		int key;
		cout << "Введите ключи " << size << " элементов очереди: " << endl;
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			cin >> key;
			push(key);
		}
	}
}

void addElement(int index, int k)
{
	if (!qSize == 0 && index >= 1 && index <= qSize && k > 0)
	{
		int i = 1;
		while (i < index)
		{
			push(head->key);
			pop();
			i++;
		}
		int key;
		cout << "Введите элементы для вставки: " << endl;
		cin.get();
		for (int j = 1; j <= k; j++)
		{
			cin >> key;
			push(key);
		}
		for (i; i <= qSize - k; i++)
		{
			push(head->key);
			pop();
		}
	}
	else cout << "Очередь пуста или введен неверный индекс" << endl;
}
void output(Point* obj)
{
	cout << obj->key << endl;
	if (obj == top) return;
	output(obj->next);
}
void printQueue()
{
	if (qSize == 0) cout << "Очередь пуста" << endl;
	else output(head);
}
void deleteElement(int key)
{
	if (qSize == 0) cout << "Очередь пуста, нечего удалять!" << endl;
	int i = 1;
	while (i <= qSize)
	{
		if (head->key == key)
		{
			pop();
		}
		else
		{
			push(head->key);
			pop();
			i++;
		}
	}
}
void deleteQueue()
{
	while (head != nullptr)
	{
		pop();
	}
	cout << " Очередь удалена!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	fprintf(file, "%d\n", obj->key);
	toFile_obj(obj->next, file);
}
void writeInFile(const char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	toFile_obj(head, file);
	fclose(file);
}
void recreateQueue(const char* filename)
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
		push(key);
	}
	fclose(file);
}
int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 10;
	int number, key, keyToDelete;
	createQueue(n);
	printQueue();
	Point* e = new Point;
	cout << "Введите позицию и количество элементов для добавления" << endl;
	cin >> number >> key;
	addElement(number, key);
	printQueue();
	cout << "Введите ключ элемента для удаления" << endl;
	cin >> keyToDelete;
	deleteElement(keyToDelete);
	printQueue();
	cout << endl;
	writeInFile("file.txt");
	deleteQueue();
	printQueue();
	recreateQueue("file.txt");
	printQueue();
	deleteQueue();
	return 0;
}