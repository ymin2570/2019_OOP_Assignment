#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])							//Passing arguments to the main function
{
	if (argc == 3)
	{
		ifstream compare1, compare2;					//read file
		string str1, str2;												//Save input string
		char buf1[100], buf2[100];							//Input buffer
		bool compare = true;									//variable for checking if two files are same
		compare1.open(argv[1]);							//Open file1
		compare2.open(argv[2]);							//Open file2
		if (!compare1.is_open() || !compare2.is_open())			//Not opened
		{
			cout << "failed file road" << endl;
			return 0;
		}

		while (!compare1.eof() && !compare2.eof())
		{
			memset(buf1, 0, 100);							//Reset
			memset(buf2, 0, 100);

			compare1.getline(buf1, sizeof(buf1));
			str1 = buf1;
			compare2.getline(buf2, sizeof(buf2));
			str2 = buf2;

			if (str1 != str2)										//If string is different
			{
				compare = false;
				break;
			}
			if ((compare1.eof() && !compare2.eof()) || !compare1.eof() && compare2.eof())				//end of file is not same
				compare = false;
			str1 = "";
			str2 = "";
		}
		compare1.close();
		compare2.close();

		if (compare == true)
			cout << "The two files are same";
		else
			cout << "The two files are different";
	}
	else
		cout << "Enter the right input format !!!";
	return 0;
}