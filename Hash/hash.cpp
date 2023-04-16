#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <time.h>
using namespace std;

string names[5] = { "Иван", "Александр", "Петр", "Дмитрий", "Денис" };
string patronymic[5] = { "Иванович", "Александрович", "Петрович", "Дмитриевич", "Юрьевич" };
string surnames[5] = { "Иванов", "Александров", "Петров", "Семёнов", "Павлов" };
int passport[5] = { 753485, 234573, 124383, 325243, 124342 };
string phone[5] = { "76937692760", "13958306837", "19603876934", "70937596837", "54079361859" };

struct Node {
    string FIO;
    string phone;
    long int passport;
    Node* next;
    Node(string fio, string phone, int pass) : FIO(fio), phone(phone), passport(pass), next(nullptr) {}
    Node(string data) : phone(data), FIO("NULL"), passport(0), next(nullptr) {}
    friend ostream& operator<<(ostream& out, const Node& node)
    {
        if (node.phone == "not found") { out << "not found"; }
        else if (node.phone == "delete") { out << "delete"; }
        else
            out << " | " << node.FIO << "\t" << node.phone << "\t" << node.passport << " | ";
        return out;
    }
};
class HashTable {
private:
    vector<Node*> table;
    int size;

    int hash(string str)
    {
        double a = (10/2486) * sumOfPhone(str);
        double c = size * (a - int(a));
        return int(c);
    }
    int sumOfPhone(string str)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += stoi(str.substr(i, 2));
        }
        return sum;
    }

public:
    int count_collision = 0;
    HashTable(int s) : size(s)
    {
        table.resize(size, nullptr);
    }
    void insert(string FIO, string key, int num) {
        int index = hash(key);
        Node* newNode = new Node(FIO, key, num);
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            count_collision++;
            Node* current = table[index];
            while (current->next != nullptr) {
                /*if (current->key == key) {
                    current->value = value;
                    return;
                }*/

                current = current->next;
            }
            /*if (current->key == key) {
                current->value = value;
                return;
            }*/
            current->next = newNode;

        }
    }
    void remove(string key) {
        int index = hash(key);
        if (table[index] == nullptr) {
            return;
        }
        else if (table[index]->phone == key) {
            Node* temp = table[index];
            table[index] = temp->next;
            delete temp;
        }
        else {
            Node* current = table[index];
            while (current->next != nullptr && current->next->phone != key) {
                current = current->next;
            }
            if (current->next != nullptr && current->next->phone == key) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }
    Node find(string key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->phone == key) {
                return *current;
            }
            current = current->next;
        }
        return Node("not found");
    }
    void print() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            if (current != nullptr) {
                cout << endl << i + 1 << ": " << *current;
                current = current->next;
            }
            while (current != nullptr) {
                cout << " ->\n   " << *current;
                current = current->next;
            }
        }
    }
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int randomNum()
{
    return rand() % 5;
}
string randomName()
{
    return (surnames[randomNum()] + " " + names[randomNum()] + " " + patronymic[randomNum()]);
}
long int randomPassport()
{
    return passport[randomNum()];
}
string randomPhone()
{
    return phone[randomNum()];
}
Node* createRandomPerson()
{
    Node* temp = new Node("not find");
    temp->FIO = randomName();
    temp->passport = randomPassport();
    temp->phone = randomPhone();
    return temp;
}

void fillArray(vector<Node*>& array, const int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = createRandomPerson();
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    int size;
    cout << "Введите количество элементов в массиве: ";
    cin >> size;
    vector<Node*> array;
    array.resize(size);
    HashTable Table(size);
    fillArray(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << i << ":\t" << *array[i] << endl;
        string FIO = array[i]->FIO;
        string phone = array[i]->phone;
        long int pass = array[i]->passport;

        Table.insert(FIO, phone, pass);
    }
    cout << endl << endl;
    Table.print();
    string fullName, name1, name2, name3, phone;
    int pass;
    /*cout << endl << "Введите элемент для добавления" << endl;
    cout << "ФИО: ";
    cin >> name1 >> name2 >> name3;
    fullName = name1 + ' ' + name2 + ' ' + name3;
    cout << "Телефон: ";
    cin >> phone;
    cout << "Паспорт: ";
    cin >> pass;
    Table.insert(fullName, phone, pass);
    Table.print();*/

   /* cout << endl << "Введите телефон для удаления из списка" << endl;
    cin >> phone;
    Table.remove(phone);
    Table.print();*/

    cout << endl << "Введите телефон для поиска элемента" << endl;
    cin >> phone;
    cout << Table.find(phone);

    cout << endl << Table.count_collision << endl;
    return 0;
}
