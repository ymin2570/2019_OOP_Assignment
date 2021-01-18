#include<iostream>
#include<string>
using namespace std;

void Appending(int arr[2][6], int *);
void Deleting(int arr[2][6], int *);
void Searching(int arr[2][6], int *);
void Sorting(int ar[2][6], int *);
int main()
{
	int arr[2][6] = {};
	int a = 0;
	int *plast = &a;
	string insert;

	cout << "#Enter function : ";
	cin >> insert;

	while (insert != "End")
	{
		if (insert == "Append")
		{
			if (*plast >= 6)				// Cannot append more if the array is full
			{
				cout << "You cannot append more value !!" << endl << endl;
				break;
			}

			else
				Appending(arr, plast);
		}

		else if (insert == "Delete")
			Deleting(arr, plast);

		else if (insert == "Search")
			Searching(arr, plast);

		else if (insert == "Sort")
			Sorting(arr, plast);

		else
		{
			cout << "Error !!" << endl << endl;
			break;
		}

		cout << "#Enter function : ";
		cin >> insert;
	}

	return 0;
}

void Appending(int arr[2][6], int *plast)
{
	int id, score;

	cin >> id >> score;

	arr[0][*plast] = id;
	arr[1][*plast] = score;
	(*plast)++;				// Save how many columns the array has in *pmax

	for (int i = 0; i < *plast; i++)			// Repeat until the value stored in the array
	{
		cout << arr[0][i] << " ";			// Print saved ID in the array
	}
	cout << endl;

	for (int i = 0; i < *plast; i++)
	{
		cout << arr[1][i] << " ";			// Print saved score in the array
	}
	cout << endl;
}

void Deleting(int arr[2][6], int *plast)
{
	int id;
	int temp = 0;
	cin >> id;

	for (int i = 0; i < *plast; i++)
	{
		if (arr[0][i] == id)
		{
			arr[0][i] = 0;
			arr[1][i] = 0;

			if (i < *plast - 1)			// Move values one space forward if ID is not the end of the array
			{
				for (int j = i; j < *plast - 1; j++)
				{
					arr[0][j] = arr[0][j + 1];
					arr[1][j] = arr[1][j + 1];
				}

				arr[0][*plast - 1] = 0;
				arr[1][*plast - 1] = 0;
			}
			(*plast)--;			// Save how many columns the array has in *pmax
			break;
		}
		temp++;					// temp used to check if Deleting function is working well
	}

	if (temp == *plast)
	{
		cout << "ID is not in the list" << endl << endl;
	}

	for (int i = 0; i < *plast; i++)
	{
		cout << arr[0][i] << " ";			// Print saved ID in the array
	}
	cout << endl;

	for (int i = 0; i < *plast; i++)
	{
		cout << arr[1][i] << " ";			// Print saved score in the array
	}
	cout << endl;
}

void Searching(int arr[2][6], int *plast)
{
	int id;
	int temp = 0;
	cin >> id;

	for (int i = 0; i < *plast; i++)
	{
		if (arr[0][i] == id)
		{
			cout << arr[0][i] << endl;					// Print ID that user input if it is in the array
			cout << arr[1][i] << endl << endl;			// Print Score that user input if it is in the array
			break;
		}
		temp++;					// temp used to check if Searching function is working well		
	}
	if (temp == *plast)
	{
		cout << "ID is not in the list" << endl << endl;
	}
}

void Sorting(int arr[2][6], int *plast)
{
	string ios;			//id or sort
	int temp;

	cin >> ios;

	if (ios == "ID")
	{
		for (int i = 0; i < *plast; i++)			// Bubble Sort by ID
		{
			for (int j = 0; j < *plast - i - 1; j++)
			{
				if (arr[0][j] > arr[0][j + 1])
				{
					temp = arr[0][j];
					arr[0][j] = arr[0][j + 1];
					arr[0][j + 1] = temp;

					temp = arr[1][j];
					arr[1][j] = arr[1][j + 1];
					arr[1][j + 1] = temp;
				}
			}
		}
	}

	else if (ios == "Score")
	{
		for (int i = 0; i < *plast; i++)			// Bubble Sort by Score
		{
			for (int j = 0; j < *plast - i - 1; j++)
			{
				if (arr[1][j] > arr[1][j + 1])
				{
					temp = arr[0][j];
					arr[0][j] = arr[0][j + 1];
					arr[0][j + 1] = temp;

					temp = arr[1][j];
					arr[1][j] = arr[1][j + 1];
					arr[1][j + 1] = temp;
				}
			}
		}
	}

	else
		cout << "Error !!" << endl << endl;

	for (int i = 0; i < *plast; i++)
	{
		cout << arr[0][i] << " ";			// Print saved ID in the array
	}
	cout << endl;

	for (int i = 0; i < *plast; i++)
	{
		cout << arr[1][i] << " ";			// Print saved score in the array
	}
	cout << endl;
}
