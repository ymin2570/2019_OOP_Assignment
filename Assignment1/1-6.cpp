#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int input;
	double distance;

	cout << "Input" << endl;
	cin >> input;

	double** ptr = new double *[input];
	int* count = NULL;

	count = new int[input];				// Dynamic allocation
	for (int i = 0; i < input; i++)
	{
		ptr[i] = new double[6];
	}

	for (int i = 0; i < input; i++)		//Input
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> ptr[i][j];
		}
	}

	for (int i = 0; i < input; i++)
	{
		distance = sqrt(pow(ptr[i][0] - ptr[i][3], 2) + pow(ptr[i][1] - ptr[i][4], 2));			// Distance between point and point

		if (distance > ptr[i][2] + ptr[i][5])			// Distance > d1 + d2
		{
			count[i] = 0;
		}

		else if (distance == ptr[i][2] + ptr[i][5])			// Distance = d1 + d2
		{
			count[i] = 1;									// circumscription
		}

		else if (distance < ptr[i][2] + ptr[i][5])			// Distance < d1 + d2
		{
			if (ptr[i][2] > ptr[i][5])
			{
				if (ptr[i][2] > ptr[i][5] + distance)
				{
					count[i] = 0;							// one circle is in another circle
				}

				else if (ptr[i][2] == ptr[i][5] + distance)
				{
					count[i] = 1;							// inscription
				}

				else
					count[i] = 2;
			}

			else if (ptr[i][2] < ptr[i][5])
			{
				if (ptr[i][5] > ptr[i][2] + distance)
				{
					count[i] = 0;							// one circle is in another circle
				}

				else if (ptr[i][5] == ptr[i][2] + distance)
				{
					count[i] = 1;							// inscription
				}

				else
					count[i] = 2;
			}

			else if (ptr[i][2] == ptr[i][5])
			{
				if ((ptr[i][0] == ptr[i][3]) && (ptr[i][1] == ptr[i][4]))		// same circle
				{
					count[i] = -1;
				}

				else
					count[i] = 2;
			}

		}

		else
			cout << "Error !!" << endl;
	}

	cout << "Output" << endl;
	for (int i = 0; i < input; i++)			//Output
	{
		cout << count[i] << endl;
	}

	delete count;
	for (int i = 0; i < input; i++)
	{
		delete ptr[i];
	}

	return 0;
}