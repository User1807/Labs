#include <D:\c++\Zadacha_3\Money.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Money>St;//стек
typedef vector<Money>Vec;//вектор

St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//ввод переменной
		s.push(m);//добавление ее в стек
	}
	return s;//вернуть стек как результат функции
}

//копирует стек в вектор
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}

void print_stack(St s)
{
	//копируем стек в вектор
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}

Money minimum(St s)
{
	Vec v = copy_stack_to_vector(s);
	Money min = s.top();
	s.pop();
	//перебор вектора
	while (!s.empty())//пока стек не пустой
	{
		if (s.top()<min)
		{
			min = s.top();
		}
		s.pop();
	}
	s = copy_vector_to_stack(v);//скопировать вектор в стек
	return min;
}
void Add_to_stack(St& s, Money el, int pos)
{
	Vec v;
	Money t;
	int i = 1;//номер элемента в стеке
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины
		//если номер равен номеру позиции, на котоую добвляем элемент 
		if (i == pos)v.push_back(el);//добавить новый элемент в вектор
		v.push_back(t);//добавить элемент из стека в вектор
		s.pop();//удалить элемент из стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
Money Srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	int n = 1;
	Money sum = s.top();//начальное значениедля суммы
	s.pop();//удалить первый элемент из вектора
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавить в сумму элемент из вершины стека
		s.pop();//удалить элемент
		n++;
	}
	s = copy_vector_to_stack(v);//скопировать вектор в стек
	return sum / n; //вернуть среднее арифметическое
}
void Delete_from_stack(St& s)
{
	Money m = Srednee(s);//находим среднее
	Vec v;
	Money t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получаем элемент из вершины стека
		//если он не равен максимальному, заносим элемент в вектор
		if (t < m)v.push_back(t);
		s.pop();//удаляем элемент из стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

//поиск максимального элемента
Money Max(St s)
{
	Money m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
//умножение на максимальный
void Multiplication(St& s)
{
	Money m = Max(s);//находим максимальный элемент
	Vec v;
	Money t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получаем элемент из вершины
			v.push_back(t * m);//умножаем t на минимальный и добавляем в вектор
		s.pop();//удаляем элемент из вершины
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

void main()
{
	Money t;
	St s;
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);//создать стек
	print_stack(s);//печать стека
	t = minimum(s);//вычисляем минимальное
	cout << "Minimum = " << minimum(s) << endl;
	cout << "Add minimum: " << endl;
	cout << "pos?";
	int pos;
	cin >> pos;//вводим позицию для добавления
	Add_to_stack(s, t, pos);//добавление элемента
	print_stack(s);//печать стека
	Delete_from_stack(s);
	print_stack(s);//печать стека
	Multiplication(s);
	print_stack(s);//печать стека
}