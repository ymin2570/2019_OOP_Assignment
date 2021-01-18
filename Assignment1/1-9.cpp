#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define RAND_MAX 65
#define ROW 9
#define COLUMN 3
using namespace std;

int main()
{
	int arr[ROW][COLUMN];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			arr[i][j] = rand() % RAND_MAX;			// Save digit 0 to 64 in array
		}
	}

	cout << "<Original>" << endl;					// Print original array
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "<Transposed>" << endl;					// Print Transposed array
	for (int i = 0; i < COLUMN; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			cout << setw(4) << arr[j][i];
		}
		cout << endl;
	}
	return 0;
}