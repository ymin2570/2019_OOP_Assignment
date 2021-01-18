#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i = 0, length = 0, digit = 0, lowercase = 0, uppercase = 0, special = 0, temp = 0;
	string password;

	cout << "Input password" << endl;
	cin >> password;

	if (password.length() < 1 || password.length() > 20)			// Set the range of password length
	{
		cout << "The length of the string should be 1 to 20 !!!" << endl;
		return 0;
	}

	while (password[i] != NULL)
	{
		if (password[i] >= 48 && password[i] <= 57)					// ASCII code of digit
		{
			digit++;
		}

		else if (password[i] >= 65 && password[i] <= 90)				// ASCII code of Uppercase
		{
			uppercase++;
		}

		else if (password[i] >= 97 && password[i] <= 122)				// ASCII code of Lowercase
		{
			lowercase++;
		}

		else if (password[i] == 33 || password[i] == 64 || password[i] == 35 || password[i] == 36
			|| password[i] == 37 || password[i] == 94 || password[i] == 38 || password[i] == 42
			|| password[i] == 40 || password[i] == 41 || password[i] == 45 || password[i] == 43)				// ASCII code of special character
		{
			special++;
		}

		length++;			// length of password
		i++;
	}
	cout << endl;
	cout << "Output" << endl;
	if (length < 6)
	{
		cout << "Must contain at least 6 characters." << endl << endl;
	}
	else
		temp++;				// Meet the condition

	if (digit < 1)
	{
		cout << "Must contain at least 1 digit." << endl << endl;
	}
	else
		temp++;

	if (uppercase < 1)
	{
		cout << "Must contain at least 1 uppercase English character." << endl << endl;
	}
	else
		temp++;

	if (lowercase < 1)
	{
		cout << "Must contain at least 1 lowercase English character." << endl << endl;
	}
	else
		temp++;

	if (special < 1)
	{
		cout << "Must contain at least 1 special character." << endl << endl;
	}
	else
		temp++;

	if (temp == 5)			// If all conditions are met
	{
		cout << "Thank you for signing up!" << endl << endl;
	}

	return 0;
}