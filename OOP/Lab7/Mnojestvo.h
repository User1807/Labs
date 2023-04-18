#include <iostream>
using namespace std;
template <class M> //M - параметр шаблона
class Mnojestvo
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Mnojestvo(int s, M k);
	//конструктор с параметрами
	Mnojestvo(const Mnojestvo<M>& a);
	//деструктор
	~Mnojestvo();
	//оператор присваивания
	Mnojestvo& operator=(const Mnojestvo<M>& a);
	//операция доступа по индексу
	M& operator[](int index);
	//операция для добавление константы
	Mnojestvo operator-(const Mnojestvo<M>& a);
	//операция, возвращающая длину вектора
	int operator()();
	//перегруженные операции ввода-вывода
	// <> - указывают на то, что функция является шаблоном
	friend ostream& operator<< <>(ostream& out, const Mnojestvo<M>& a);
	friend istream& operator>> <>(istream& in, Mnojestvo<M>& a);
private:
	int size;//размер вектора
	M* data;//укзатель на динамический массив значений вектора
};

//опрeделение функций
//конструктор с параметрами
template <class M>
Mnojestvo<M>::Mnojestvo(int s, M k)
{
	size = s;
	data = new M[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//конструктор копирования
template <class M>
Mnojestvo<M>::Mnojestvo(const Mnojestvo& a)
{
	size = a.size;
	data = new M[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//деструктор
template <class M>
Mnojestvo<M>::~Mnojestvo()
{
	delete[]data;
	data = 0;
}
//операция присваивания
template <class M>
Mnojestvo<M>& Mnojestvo<M>::operator=(const Mnojestvo<M>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new M[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
//операция доступа по индексу
template <class M>
M& Mnojestvo<M>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция разности множеств
template <class M>
Mnojestvo<M> Mnojestvo<M>::operator-(const Mnojestvo<M>& a)
{
	Mnojestvo<M> temp(size, *data);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] - a.data[i];
	return temp;
}
//операция для получения длины вектора
template <class M>
int Mnojestvo<M>::operator ()()
{
	return size;
}
//операции для ввода-вывода
template <class M>
ostream& operator<<(ostream& out, const Mnojestvo<M>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class M>
istream& operator>>(istream& in, Mnojestvo<M>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}