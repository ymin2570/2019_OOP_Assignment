#include<iostream>
#include<string>
using namespace std;

string timeInWords(int h, int m, string arr[])
{
	if (h >= 1 && h <= 12)				// 1 <= hour <= 12
	{
		if (m == 0)
		{
			return arr[h] + " " + arr[m];
		}

		else if (1 <= m && m <= 30)
		{
			if (m == 1)
			{
				return arr[m] + " minute past " + arr[h];
			}

			else if (m == 15 || m == 30)
			{
				return arr[m] + " past " + arr[h];
			}

			else
			{
				return arr[m] + " minutes past " + arr[h];
			}

		}

		else if (30 < m && m <= 59)
		{
			if (m == 45)
			{
				if (h = 12)				// if hour is 12, print one
				{
					return arr[60 - m] + " to " + arr[h - 11];
				}
				else
					return arr[60 - m] + " to " + arr[h + 1];
			}

			else
			{
				if (h == 12)
				{
					return arr[60 - m] + " minutes to " + arr[h - 11];
				}
				else
					return arr[60 - m] + " minutes to " + arr[h + 1];
			}
		}

		else
			cout << "Error !! (minute is out of range)" << endl;			// if minute is out of range
	}
	else
		cout << "Error !! (hour is out of range)" << endl;					// if hour is out of range
}


int main()
{
	string arr[] = { "o' clock", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	  "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
	  "twenty one","twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half" };		// Declaring an array to replace a number with a string

	int hour, minute;

	cout << "Input" << endl;
	cin >> hour;
	cin >> minute;
	cout << endl;
	cout << "Output" << endl;
	cout << timeInWords(hour, minute, arr) << endl;

	return 0;
}