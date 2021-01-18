#include<iostream>
#include<fstream>				//ifstream, ofstream
#include<cstring>				//strcpy
#include<cstdlib>				//atoi
using namespace std;

int main()
{
	fstream numbers;							//read and write file
	char buf[100];									//Input buffer
	char arr[100][100] = { NULL };
	int i = 0;											//last index
	numbers.open("numbers.txt");
	if (!numbers.is_open())				//Not opened
	{
		cout << "failed file road" << endl;
		return 0;
	}
	while (!numbers.eof())
	{
		memset(buf, 0, 100);
		numbers.getline(buf, sizeof(buf));			//Save string consisting of numbers
		if (*buf != NULL)
		{
			strcpy(arr[i], buf);										//copy buf to arr
			i++;
		}
	}
	for (int j = 0; j < 100; j += 2)
	{
		if (*arr[j + 2] == NULL || *arr[j + 1] == NULL)
			break;
		itoa(atoi(arr[j]) + atoi(arr[j + 1]) + atoi(arr[j + 2]), arr[i], 10);					//Calculate sum of numbers
		i++;
	}
	numbers.close();
	numbers.open("numbers.txt");
	if (!numbers.is_open())				//Not opened
	{
		cout << "failed file road" << endl;
		return 0;
	}
	for (int k = 0; k < i; k++)
	{
		if (*arr[k] == NULL)
			break;
		numbers << arr[k] << endl;					//Input number in file
		cout << arr[k] << endl;
	}
	return 0;
}