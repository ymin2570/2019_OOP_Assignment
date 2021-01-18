#include<iostream>
#include<fstream>	//ifstream
#include<string>	//string, strtok
#include<iomanip>	//setw
#include<cstdlib>	//atoi
using namespace std;

void Calculate(int &, int &, int &, int &, int &, int, int *);

int main()
{
	ifstream fin;		//File input
	ofstream fout;			//File output
	string destination;			//destination that user input
	int year, month, day, hour, min, i = 0, j = 0;		//integer variable that user input and index variable
	int Minute[20] = {};			//Save the minute from the file
	char slash, colon, buf[1000];		//char variable to get slash and colon,buffer to get string
	char country[20][50] = {};		//Save the country name from the file

	fin.open("flight_time.txt");
	if (!fin.is_open())			//if file is not opened
	{
		cout << "failed file road" << endl;
		return 0;
	}

	cout << "\"flight_time.txt\"" << endl;
	while (!fin.eof())
	{
		memset(buf, 0, 1000);					//Initialize buffer
		fin.getline(buf, sizeof(buf));
		cout << buf << endl;
		while (true)
		{
			country[i][j] = buf[j];				//get country name from file
			if (buf[j + 1] == ':')
				break;
			j++;
		}
		char *tok1 = strtok(buf, "[]");
		Minute[i] = atoi(strtok(NULL, "[]"));		//get time from file
		i++;
		j = 0;
	}
	fin.close();
	i = -1;

	cout << "--------------------------------------" << endl;
	cout << "-Input form users" << endl;		//Input form
	cout << "Departure date :  2018/04/05" << endl;
	cout << "Departure time :  23:59" << endl;
	cout << "Destination :  Tokyo" << endl;
	cout << "--------------------------------------" << endl;
	cout << "-Result screen" << endl;			//Input
	cout << "Departure date : ";
	cin >> year >> slash >> month >> slash >> day;			//Input format YYYY/MM/DD
	cout << "Departure time : ";
	cin >> hour >> colon >> min;			//Input format HH:MM
	cout << "Destination : ";
	cin >> destination;

	for (int j = 0; j < 20; j++)
	{
		if (destination == country[j])				//find the same country with user input
		{
			i = j;
			break;
		}
	}

	if (i == -1)
	{
		cout << "Invalid destination !!!";
		return 0;
	}

	Calculate(year, month, day, hour, min, i, Minute);

	cout << endl << endl;
	cout.fill('0');				//fill blank with '0'
	cout << "Arrival date : " << year << slash << setw(2) << month << slash << setw(2) << day << endl;
	cout << "Arrival time : " << setw(2) << hour << colon << setw(2) << min;

	fout.open("output_file.txt");			//Not opened
	if (!fout.is_open())
	{
		cout << "failed file road" << endl;
		return 0;
	}
	fout << "Arrival date: " << year << slash << setw(2) << month << slash << setw(2) << day << endl;
	fout << "Arrival time : " << setw(2) << hour << colon << setw(2) << min;
	return 0;
}

void Calculate(int &year, int &month, int &day, int &hour, int &min, int i, int *Minute)
{
	if (min + (Minute[i] % 60) >= 60)			//Calculate minute and if minute >= 60, hour += 1
	{
		min = min + (Minute[i] % 60) - 60;
		hour++;
	}
	else if (min + (Minute[i] % 60) < 60 && min + (Minute[i] % 60) >= 0)
	{
		min = min + (Minute[i] % 60);
	}

	if (hour + (Minute[i] / 60) >= 24)		//Calculate hour and if hour >=24, day += 1
	{
		hour = hour + (Minute[i] / 60) - 24;
		day++;
	}
	else if (hour + (Minute[i] / 60) < 24 && hour + (Minute[i] / 60) >= 0)
	{
		hour = hour + (Minute[i] / 60);
	}

	if (month == 2)			//In february, if day > 28, month++
	{
		if (day > 28)
		{
			month++;
			day = day - 28;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 ||					//Calculate month
		month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			month++;
			day = day - 30;
		}
	}

	if (month > 12)			//Calculate year
	{
		year++;
		month = month - 12;
	}
	return;
}