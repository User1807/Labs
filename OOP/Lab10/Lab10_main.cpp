#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"
using namespace std;
void main()
{
	Money m, m1, m2, toDelete;
	int n, k, c;
	char file_name[30];
	do
	{ //Μενώ
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete records from file";
		cout << "\n4. Add records to file";
		cout << "\n5. Change records in file";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "file name? "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			break;
		case 2: cout << "file name? "; cin >> file_name;
			cout << endl;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
			break;
		case 3: cout << "file name? "; cin >> file_name;
			int nom;
			cout << "value? "; cin >> toDelete;
			k = del_file(file_name, toDelete);
			if (k < 0)cout << "Can't read file";
			break;
		case 4: cout << "file name? ";
			int numOfValues;
			cin >> file_name;
			cout << "after what nom? "; cin >> nom;
			cout << "number of values? "; cin >> numOfValues;
			for (int i = 0; i < numOfValues; i++)
			{
				cout << "New value: ";
				cin >> m1;
				k = add_file(file_name, nom+i+1, m1);
			}
			if (k < 0) cout << "Can't read file";
			if (k == 0)
			{
				for (int i = 0; i < numOfValues; i++)
					k = add_end(file_name, m1);
			}
			break;
		case 5: cout << "file name? ";
			cin >> file_name;
			cout << "value: ";
			cin >> m2;
			k = change_file(file_name, m2);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		}
	} while (c != 0);
}