#include<iostream>
using namespace std;

int main()
{
	int initial = 20000;
	int distance = 0;
	int Fare = 720;

	cout << "Initial balance : " << initial << endl << endl;
	cout << "Entering each travel distance : ";
	cin >> distance;
	cout << "-----------------------------------------------";
	cout << endl;

	while (distance != -1)
	{
		if (distance < 4)			// Set the range of distance
		{
			cout << "Minimum distance is 4 !!!" << endl << endl;
			cout << "Current balance : " << initial << endl << endl;
			cout << "Program exit.";
			return 0;
		}

		else if (distance > 178)			// Set the range of distance
		{
			cout << "Maximum distance is 178 !!!" << endl;
			cout << "Current balance : " << initial << endl << endl;
			cout << "Program exit.";
			return 0;
		}

		if (distance > 40)
			Fare = 720 + 80 * ((distance - 40) / 8);		// Calculate the fare based on distance that user entered

		if (initial - Fare < 0)						// exit the program if it cannot be deducted anymore
		{
			cout << "You cannot move !!!" << endl;
			cout << "Current balance : " << initial << endl << endl;
			cout << "Program exit.";
			return 0;
		}

		cout << "Fare : " << Fare << endl << endl;
		cout << "Current balance: " << initial - Fare << endl << endl;
		initial -= Fare;
		cout << "Entering each travel distance : ";
		cin >> distance;
		cout << "-----------------------------------------------";
		cout << endl;
	}

	cout << "Program exit.";

	return 0;
}