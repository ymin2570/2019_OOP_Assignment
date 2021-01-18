#include<iostream>
using namespace std;

int main()
{
	int size;

	cout << "Enter the size of asterisk: ";
	cin >> size;

	if (size < 5 || size > 29)		// Set the range of size
	{
		cout << "size should be 5 to 29 !!!" << endl << endl;
		return 0;
	}

	for (int i = 0; i < (size / 2) + 1; i++)		// Upper part based on line that printed only one $ and that line
	{
		for (int j = 0; j < size; j++)
		{
			if (j == i || j == size / 2 || j == size - 1 - i)		// $ output condition
			{
				cout << "$";
			}
			else
				cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < (size / 2); i++)			// Lower part based on line that printed only one $
	{
		for (int j = 0; j < size; j++)
		{
			if (j == (size / 2) - 1 - i || j == (size / 2) || j == size + i - (size / 2))		// $ output condition
			{
				cout << "$";
			}

			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < size / 2 + 1; i++)			// Upper part based on line that printed $ as many as size and that line
	{
		for (int j = 0; j < size / 2 - i; j++)		// Output blank
		{
			cout << " ";
		}

		for (int k = 0; k < (2 * i) + 1; k++)		// Output $
		{
			cout << "$";
		}
		cout << endl;
	}

	for (int i = 0; i < size / 2; i++)				// lower part based on line that printed $ as many as size and that line
	{
		for (int j = 0; j < i + 1; j++)				// Output blank
		{
			cout << " ";
		}

		for (int k = 0; k < size - (2 * (i + 1)); k++)			// Output $
		{
			cout << "$";
		}
		cout << endl;
	}

	return 0;
}