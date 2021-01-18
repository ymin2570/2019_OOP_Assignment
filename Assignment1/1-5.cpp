#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	string str;
	int n = 6, i = 0;
	int total = 0;

	cout << "Input : ";
	getline(cin, str);

	while (str[i] != NULL)			// Check input string
	{
		if (((65 <= str[i]) && (str[i] <= 90)) || ((97 <= str[i]) && (str[i] <= 122)))		// Count a number of characters
		{
			total++;
		}
		i++;
	}

	i = 0;
	cout << endl << "Output" << endl;

	for (int j = 65; j <= 90; j++)		// ASCII code in upper case letters
	{
		int count = 0;

		while (str[i] != NULL)
		{
			if (str[i] == (char)j || str[i] == (char)(j + 32))		// Check is it an alphabet
			{
				count++;
			}
			i++;
		}
		i = 0;

		if (count != 0)			// When an alphabet is in a string
		{
			cout << (char)j << "(" << (char)(j + 32) << ") ";			// Print that alphabet
			cout << fixed << setprecision(n) << (double)count / (double)total << endl;
		}
	}

	return 0;
}