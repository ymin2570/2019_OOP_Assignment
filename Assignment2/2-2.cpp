#include<iostream>
using namespace std;

int CMPandCAT(char *, char *, char *);

int main()
{
	char src1[50] = {}, src2[50] = {}, copy_result[100] = {};			//string to save input
	int return_value;																					//return value of function
	cout << "Input string:" << endl;		//Input
	cout << "src1 : ";
	cin >> src1;
	cout << "src2 : ";
	cin >> src2;

	return_value = CMPandCAT(src1, src2, copy_result);		//Function called
	cout << "Output string" << endl;						//Output
	cout << "Return value: " << return_value << endl;
	cout << "copy_result : " << copy_result;
	return 0;
}

int CMPandCAT(char *src1, char *src2, char *copy_result)
{
	int i = 0, j = 0, check = 0;
	if (src1[i + 1] == NULL && src2[i + 1] != NULL)				//if src2 is longer than src1
		check = -1;
	else if (src1[i + 1] != NULL && src2[i + 1] == NULL)				//if src1 is longer than src2
		check = 1;

	while (src1[i] != NULL && src2[i] != NULL)				//Check larger string
	{
		if (src1[i + 1] == NULL && src2[i + 1] != NULL)				//if src2 is longer than src1
		{
			check = -1;
			break;
		}
		else if (src1[i + 1] != NULL && src2[i + 1] == NULL)				//if src1 is longer than src2
		{
			check = 1;
			break;
		}
		if (src1[i] > src2[i])				//Compare src1 and src2
		{
			check = 1;
			break;
		}
		else if (src2[i] > src1[i])
		{
			check = -1;
			break;
		}
		else
			i++;
	}

	if (check == -1)					//src2 > src1
	{
		i = 0;
		while (src2[i] != NULL)
		{
			copy_result[i] = src2[i];
			i++;
		}
		while (src1[j] != NULL)
		{
			copy_result[i] = src1[j];
			i++;
			j++;
		}

		return check;
	}
	else if (check == 1)				// src1 > src2
	{
		i = 0;
		while (src1[i] != NULL)
		{
			copy_result[i] = src1[i];
			i++;
		}
		while (src2[j] != NULL)
		{
			copy_result[i] = src2[j];
			i++;
			j++;
		}
		return check;
	}
	else
	{									// src1 = src2
		i = 0;
		while (src1[i] != NULL)
		{
			copy_result[i] = src1[i];
			i++;
		}
		while (src2[j] != NULL)
		{
			copy_result[i] = src2[j];
			i++;
			j++;
		}
		return check;
	}
}