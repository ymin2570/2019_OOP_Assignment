#include<iostream>
using namespace std;

int main()
{
	double a, b, c;
	double max = 0, min = 0;

	cout << "Input integer a : ";
	cin >> a;

	cout << "Input integer b : ";
	cin >> b;

	cout << "Input integer c : ";
	cin >> c;

	min = (a * -30 * -30) + (b * -30) + c;
	max = (a * 30 * 30) + (b * 30) + c;

	for (int i = -30; i <= 30; i++)
	{
		if (max <= (a * i * i) + (b * i) + c)
		{
			max = (a * i * i) + (b * i) + c;
		}

		if (min >= (a * i * i) + (b * i) + c)
		{
			min = (a * i * i) + (b * i) + c;
		}
	}

	cout << "Maximum value is " << max << endl;
	cout << "Minimum value is " << min << endl;
	return 0;
}