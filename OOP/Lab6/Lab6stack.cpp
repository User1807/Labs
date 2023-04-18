#include "Stack.h";

int main()
{
	Stack stack(5);
	stack.Show();
	cout << endl;
	stack.Pop();
	stack.Push("9999");
	stack.Show();
	cout << endl;
	Stack stack2;
	stack2 = stack;
	stack2.Show();
	cout << "\nStack size: " << stack2();

	return 0;
}