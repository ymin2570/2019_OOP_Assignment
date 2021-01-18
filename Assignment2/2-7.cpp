#include<iostream>
#include<fstream>			//ifstream
#include<iomanip>			//new int
using namespace std;

void Sort(char **, int);
int main()
{
	ifstream words;																	//read file
	int num_word = 0, count = 0,										//count the number of words and length of words
		indxS = 0, indxE = -1, indx = 0;								//index of word
	char buf[1000];																	//Input buffer
	words.open("words.txt");

	if (!words.is_open())															//not opened
	{
		cout << "failed file road" << endl;
		return 0;
	}

	while (!words.eof())
	{
		memset(buf, 0, 1000);
		words.getline(buf, sizeof(buf));
		for (int i = 0; i < 1000; i++)
		{
			if (buf[i] == NULL)
				break;
			else if (buf[i] == ' ')
				num_word++;													//Count the number of words
		}
		num_word++;
		cout << buf << endl;
	}
	words.close();
	buf[0] = NULL;															//Reset
	char ** arr = new char *[num_word];					//Dynamic allocate two-dimension
	for (int i = 0; i < num_word; i++)
	{
		arr[i] = new char[15];
		memset(arr[i], 0, sizeof(char) * 15);
	}

	words.open("words.txt");
	while (!words.eof())
	{
		indxS = 0, indxE = -1;
		memset(buf, 0, 1000);
		words.getline(buf, sizeof(buf));
		for (int i = 0; i < 1000; i++)
		{
			if (buf[i] == NULL)
				break;
			else if (buf[i] >= 65 && buf[i] <= 90)				//Upper case
			{
				if (buf[i + 1] >= 65 && buf[i + 1] <= 90)
				{
					if (i == 0)
						indxS = i;
					else
					{
						if (buf[i - 1] == ' ')
							indxS = i;
					}
				}
				else if (buf[i + 1] >= 97 && buf[i + 1] <= 122)
				{
					if (i == 0)
						indxS = i;
					else
					{
						if (buf[i - 1] == ' ')
							indxS = i;
					}
				}
				else if (buf[i + 1] == ' ' || buf[i + 1] == NULL)					//find word
				{
					if (i == 0)
						indxS = i;
					else
						if (buf[i - 1] == ' ')
							indxS = i;
					indxE = i;
				}
				count++;																					//length of word
			}
			else if (buf[i] >= 97 && buf[i] <= 122)							//Lower case
			{
				if (buf[i + 1] >= 65 && buf[i + 1] <= 90)
				{
					if (i == 0)
						indxS = i;
					else
					{
						if (buf[i - 1] == ' ')
							indxS = i;
					}
				}
				else if (buf[i + 1] >= 97 && buf[i + 1] <= 122)
				{
					if (i == 0)
						indxS = i;
					else
					{
						if (buf[i - 1] == ' ')
							indxS = i;
					}
				}
				else if (buf[i + 1] == ' ' || buf[i + 1] == NULL)				//find word
				{
					if (i == 0)
						indxS = i;
					else
						if (buf[i - 1] == ' ')
							indxS = i;
					indxE = i;
				}
				count++;																					//length of word
			}
			else if (buf[i] == ' ' || buf[i] == NULL)								//new word
			{
				count = 0;
				continue;
			}

			if (count >= 15)
			{
				cout << "word should less than 15 characters" << endl;
				return 0;
			}
			if (indxE >= indxS)													//save word in arr
			{
				for (int k = indxS; k <= indxE; k++)
				{
					arr[indx][k - indxS] = buf[k];
				}
				indx++;
			}
		}
	}
	words.close();
	Sort(arr, num_word);

	/////////////////////////////////////////print
	cout << endl;
	for (int i = 0; i < num_word; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (arr[i][j] != NULL)
				cout << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < num_word; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}

void Sort(char **arr, int num_word)
{
	/////////////////////////////////////////Sort by bubble sort
	char temp_arr[15] = {};								//array to change
	bool change = false, change_b = false, change_a = false;						//find to change and face that before array is changed and after array is changed

	for (int i = 0; i < num_word; i++)
	{
		for (int j = 0; j < num_word - i - 1; j++)
		{
			for (int k = 0; k < 15; k++)
			{
				change_b = false, change_a = false;
				if (arr[j][k] == arr[j + 1][k])
					change = false;
				else
				{
					if (arr[j][k] >= 97 && arr[j][k] <= 122)						//Lower case
					{
						if (arr[j + 1][k] >= 65 && arr[j + 1][k] <= 90)				//Upper case
						{
							arr[j + 1][k] += 32;												//for compare case-insensitive 
							change_a = true;
						}
					}
					else if (arr[j][k] >= 65 && arr[j][k] <= 90)						//Upper case
					{
						if (arr[j + 1][k] >= 97 && arr[j + 1][k] <= 122)					//Lower case
						{
							arr[j][k] += 32;
							change_b = true;
						}
					}
					if (arr[j][k] > arr[j + 1][k])								//If before array is larger than after array
					{
						change = true;
						if (change_a == true)										//change to original form
							arr[j + 1][k] -= 32;
						else if (change_b == true)
							arr[j][k] -= 32;
						break;
					}
					else
					{
						if (arr[j][k] == arr[j + 1][k])
						{
							if (change_a == true)												//chane to original form
								arr[j + 1][k] -= 32;
							else if (change_b == true)
								arr[j][k] -= 32;
							continue;
						}
						else
						{
							if (change_a == true)											//chane to original form
								arr[j + 1][k] -= 32;
							else if (change_b == true)
								arr[j][k] -= 32;
							break;
						}
					}
				}
			}
			if (change == true)
			{
				for (int l = 0; l < 15; l++)												//change word
				{
					temp_arr[l] = arr[j][l];
					arr[j][l] = arr[j + 1][l];
					arr[j + 1][l] = temp_arr[l];
					if (arr[j][l] == NULL && arr[j + 1][l] == NULL)
						break;
				}
			}
			change = false, change_a = false, change_b = false;
		}
	}
	return;
}