#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	try
	{
		Vector z;
		cout << "Size of vector?" << endl;
		int size;
		cin >> size;
		Vector x(size);
		cout << "Enter " << size << " elements of vector X" << endl;
		cin >> x;
		cout << "X: " << x;
		cout << "Nomer?" << endl;
		int i;
		cin >> i;
		cout << x[i] << endl;
		Vector y(size);
		cout << "Enter " << size << " elements of vector Y" << endl;
		cin >> y;
		cout << "Y: " << y;
		cout << "Nomer?" << endl;
		int j;
		cin >> j;
		cout << y[j] << endl;
		z = x -  y;
		cout << "Z: " << z << endl;
		while(true)
		{
			cout << "X: " << x << endl;
			--x;
		}
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}
