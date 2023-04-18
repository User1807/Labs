#include <iostream>
using namespace std;
template <class M> //M - �������� �������
class Mnojestvo
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	Mnojestvo(int s, M k);
	//����������� � �����������
	Mnojestvo(const Mnojestvo<M>& a);
	//����������
	~Mnojestvo();
	//�������� ������������
	Mnojestvo& operator=(const Mnojestvo<M>& a);
	//�������� ������� �� �������
	M& operator[](int index);
	//�������� ��� ���������� ���������
	Mnojestvo operator-(const Mnojestvo<M>& a);
	//��������, ������������ ����� �������
	int operator()();
	//������������� �������� �����-������
	// <> - ��������� �� ��, ��� ������� �������� ��������
	friend ostream& operator<< <>(ostream& out, const Mnojestvo<M>& a);
	friend istream& operator>> <>(istream& in, Mnojestvo<M>& a);
private:
	int size;//������ �������
	M* data;//�������� �� ������������ ������ �������� �������
};

//���e������� �������
//����������� � �����������
template <class M>
Mnojestvo<M>::Mnojestvo(int s, M k)
{
	size = s;
	data = new M[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//����������� �����������
template <class M>
Mnojestvo<M>::Mnojestvo(const Mnojestvo& a)
{
	size = a.size;
	data = new M[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class M>
Mnojestvo<M>::~Mnojestvo()
{
	delete[]data;
	data = 0;
}
//�������� ������������
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
//�������� ������� �� �������
template <class M>
M& Mnojestvo<M>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� �������� ��������
template <class M>
Mnojestvo<M> Mnojestvo<M>::operator-(const Mnojestvo<M>& a)
{
	Mnojestvo<M> temp(size, *data);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] - a.data[i];
	return temp;
}
//�������� ��� ��������� ����� �������
template <class M>
int Mnojestvo<M>::operator ()()
{
	return size;
}
//�������� ��� �����-������
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