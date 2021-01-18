#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;

	cout << "Enter the size of Magic Square : ";
	cin >> n;

	if (n < 3 || n > 15)			// Set the range of size of MagicSquare
	{
		cout << "size should be 3 to 15 !!!" << endl;
		return 0;
	}

	if (n % 2 == 0)					// if input is even integer
	{
		cout << "size should be odd integer !!!" << endl;
		return 0;
	}

	int **MagicSquare = new int *[n];
	int i = 0, j = n / 2;

	for (int k = 0; k < n; k++)
	{
		MagicSquare[k] = new int[n];
	}

	for (int num = 1; num <= (n * n); num++)				// The algorithm of the MagicSquare
	{
		MagicSquare[i][j] = num;

		if (num % n == 0)
		{
			i++;
		}
		else
		{
			i--;
			j++;

			if (i < 0)
			{
				i = n - 1;
			}
			if (j > (n - 1))
			{
				j = 0;
			}
		}

	}
	for (i = 0; i < n; i++)						// Output
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(4) << MagicSquare[i][j];
		}
		cout << endl;
	}

	for (i = 0; i < n; i++)
	{
		delete MagicSquare[i];
	}
	return 0;
}