#include<fstream>//fstream
#include"Cache.h"

int main()
{
	fstream sentences;			//To read file
	string str = "";						//To store line by line of the file
	string word = "";				//To store the word
	string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";		//To find if the alphabets exist in the string
	CacheManager *list = new CacheManager();		//CacheManager
	char buf[1000];
	int timestamp = 1;			//Timestamp for using LRU
	sentences.open("sentences.txt");
	if (!sentences.is_open())	//Not opened
	{
		cout << "File is not opened !!!" << endl;
		return 0;
	}
	while (!sentences.eof())
	{
		memset(buf, 0, 1000);
		sentences.getline(buf, sizeof(buf));
		str = buf;											//Store one line from file in str
		string::iterator i = str.begin();	//To distinguish it is alphabets or not
		for (; i != str.end(); i++)
		{
			if (alphabets.find(*i) != string::npos) {		//Character is alpahbet
				word += *i;														//Save that character in word string
				continue;
			}
			if (word != "") {
				list->Operation(word, timestamp);		//Pass the created word and its timestamp
				timestamp++;
			}
			word = "";															//Reset
		}
		if (word != "") {
			list->Operation(word, timestamp);
			timestamp++;
		}
		word = "";
	}
	return 0;
}