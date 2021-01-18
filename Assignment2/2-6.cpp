#include<iostream>
using namespace std;

void Same(char *arr, int *words)
{
	int indxS = 0, indxE = -1,						//index of word
		comS = 0, comE = -1,							//index of word for compare
		length = 0, count = 0;							//variable to find condition is meeted
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] == '!')
			break;
		//////////////////////////////////////////////////Find start index of word and end index of word
		if (arr[i] >= 65 && arr[i] <= 90)						//If Upper case
		{
			if (arr[i + 1] >= 65 && arr[i + 1] <= 90)				//next character is Upper case
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
			}
			else if (arr[i + 1] >= 97 && arr[i + 1] <= 122)				//next character is Lower case
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
			}
			else if (arr[i + 1] == ' ' || arr[i + 1] == NULL)					//next character is NULL or blank
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
				indxE = i;
			}
		}
		else if (arr[i] >= 97 && arr[i] <= 122)							//If Lower case
		{
			if (arr[i + 1] >= 65 && arr[i + 1] <= 90)
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
			}
			else if (arr[i + 1] >= 97 && arr[i + 1] <= 122)
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
			}
			else if (arr[i + 1] == ' ' || arr[i + 1] == NULL)
			{
				if (i == 0)
					indxS = i;
				else
					if (arr[i - 1] == ' ')
						indxS = i;
				indxE = i;
			}
		}
		else if (arr[i] == ' ' || arr[i] == NULL)							//If character is NULL or blank
			continue;

		//////////////////////////////////////////////////Find same words
		if (indxE != -1)			//indxE is determined
		{
			if (indxS <= indxE)			//Is correct word
			{
				length = indxE - indxS;			//actual length of word is +1
				for (int j = indxE + 2; j < 1000; j++)
				{
					if (arr[j] == '!')
						break;
					if (arr[j] >= 65 && arr[j] <= 90)			//Upper case
					{
						if (arr[j + 1] >= 65 && arr[j + 1] <= 90)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
						}
						else if (arr[j + 1] >= 97 && arr[j + 1] <= 122)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
						}
						else if (arr[j + 1] == ' ' || arr[j + 1] == NULL)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
							comE = j;
						}
					}
					else if (arr[j] >= 97 && arr[j] <= 122)				//Lowercase
					{
						if (arr[j + 1] >= 65 && arr[j + 1] <= 90)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
						}
						else if (arr[j + 1] >= 97 && arr[j + 1] <= 122)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
						}
						else if (arr[j + 1] == ' ' || arr[j + 1] == NULL)
						{
							if (j == 0)
								comS = j;
							else
								if (arr[j - 1] == ' ')
									comS = j;
							comE = j;
						}
					}
					else if (arr[j] == ' ' || arr[j] == NULL) 			//Blank or NULL
						continue;
					if (comE != -1)				//comE is determined
					{
						if (comS <= comE)
						{
							if (length == comE - comS && comS != indxS)			//consider length and not for itself
							{
								for (int k = 0; k <= length; k++)
								{
									if (arr[indxS + k] == arr[comS + k] || arr[indxS + k] == arr[comS + k] + 32 || arr[indxS + k] + 32 == arr[comS + k])
									{
										count++;
									}
								}
								if (count == length + 1)						//Two words are same
								{
									(*words)--;
									for (int l = comS; l <= comE; l++)
										arr[l] = NULL;
								}
								count = 0;						//reset
							}
						}
					}
				}
				length = 0;
			}
		}
	}
	return;
}
int main()
{
	char arr[1000] = {};
	int words = 0;

	cout << "Input : ";
	cin.getline(arr, 1000);						//Save input in arr

	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] == NULL)
		{
			arr[i + 1] = '!';					//Set ! rather than NULL that is last of the array to end for loop
			break;
		}
		else if (arr[i] >= 65 && arr[i] <= 90)
		{
			if (arr[i + 1] == ' ' || arr[i + 1] == NULL)					//count a number of words
			{
				words++;
			}
		}
		else if (arr[i] >= 97 && arr[i] <= 122)
		{
			if (arr[i + 1] == ' ' || arr[i + 1] == NULL)
			{
				words++;
			}
		}
	}
	if (arr[0] != NULL)
		Same(arr, &words);			//Function that find same word that case-insensitive
	else if (arr[0] == NULL)
		cout << "Enter the array !!!" << endl;
	cout << endl << endl << "Output : " << words;
	return 0;
}