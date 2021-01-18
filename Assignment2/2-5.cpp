#include<iostream>
#include<string>																		//string, strtok
#include<vector>																	//vector
#include<sstream>																	//strinfstream
using namespace std;

string EraseBlank(string &infixExpression);					//Erase blank function
string Postfix(string infixExpression, int &);					//Change infix to postfix
double Calculate(string postfixExpression);					//Calculate postfixExpression
string simbols = "(+-*/)";														//To find whether operator or not

int main()
{
	string infixExpression;							//Input formula
	string postfixExpression;					//Changed formula for easy to calculate
	int count = 0;											//Condition for the number of character
	double calculate = 0;							//Output value

	cout << "Input : ";
	getline(cin, infixExpression);					//Get formula
	EraseBlank(infixExpression);				//Erase blanks of the formula
	cout << endl;

	postfixExpression = Postfix(infixExpression, count);			//change infixExpression to postfixExpression
	if (count > 50)																		//Condition that up to 50 operators and parentheses and numbers
	{
		cout << "you should enter up to 50 !!!" << endl;
		return 0;
	}
	calculate = Calculate(postfixExpression);						//Calculate the postfixExpression formula
	cout << "Output : " << calculate;
	return 0;
}

string EraseBlank(string &infixExpression)
{
	char *arr = new char[infixExpression.size() + 1];
	char *buf = new char[infixExpression.size() + 1];
	strcpy_s(buf, infixExpression.size() + 1, infixExpression.c_str());				//copy infixExpression into buf array
	char *tok1 = strtok(buf, " ");						//Divide characters by spaces
	strcpy(arr, tok1);
	while (tok1 = strtok(NULL, " "))
	{
		strcat(arr, tok1);										//Combines characters with spaces removed
	}
	infixExpression = arr;									//Enter a string with no spaces into infixExpression string
	delete[] arr;
	delete[] buf;
	return infixExpression;
}

string Postfix(string infixExpression, int &count)
{
	string postfixExpression;
	vector<char> oper;															//stack for operators
	string::iterator i = infixExpression.begin();				//character of string

	for (; i != infixExpression.end(); i++)
	{
		if (simbols.find(*i) == string::npos)						//if character is number
		{
			postfixExpression += *i;
			continue;
		}
		postfixExpression += " ";											//blank to distinguish with other numbers or operators
		count++;																			//count numbers
		switch (*i)
		{
		case '(':
			oper.push_back('(');													//Add if character is '('
			count++;																		//count '('
			break;
		case ')':
			while (oper.back() != '(')										//Calculate until top of "oper" is '(' 
			{
				postfixExpression += oper.back();
				postfixExpression += " ";
				oper.pop_back();													//Delete the top of operator in "oper"
			}
			oper.pop_back();														//To eliminate '('
			count++;																		//count ')'
			break;
		case '+':
		case '-':
			while (oper.size() != 0 && oper.back() != '(')  //'(' is not to be added in postfixExpression
			{
				postfixExpression += oper.back();
				postfixExpression += " ";
				oper.pop_back();
				count++;																	//count operator
			}
			oper.push_back(*i);
			break;
		case '*':
		case '/':
			while (oper.size() != 0 && (oper.back() == '*' || oper.back() == '/'))	//Previous operator has higher priority
			{
				postfixExpression += oper.back();
				postfixExpression += " ";
				oper.pop_back();
				count++;																	//count operator
			}
			oper.push_back(*i);
			break;
		default:
			break;
		}
	}
	unsigned int OperSize = oper.size();							//Add the remaining operators in postfixExpression
	for (unsigned int i = 0; i < OperSize; ++i)
	{
		postfixExpression += " ";
		postfixExpression += oper.back();
		oper.pop_back();
		count++;																			//count operator
	}
	return postfixExpression;
}

double Calculate(string postfixExpression)
{
	vector<double> num;											//stack for numbers
	string str = "";															//To get characters
	stringstream temp(postfixExpression);			//To deliver a character

	while (!temp.eof())
	{
		temp >> str;														//Receive character by blank
		if (simbols.find(str) == string::npos)		//character is number
		{
			double dtemp;
			stringstream(str) >> dtemp;
			num.push_back(dtemp);								//Store number in stack as a double type
		}
		else
		{
			double d1, d2;													//If character is operator
			d2 = num.back();
			num.pop_back();
			d1 = num.back();
			num.pop_back();
			switch (simbols[simbols.find(str)])		//Append calculated number into "num"
			{
			case '+':
				num.push_back(d1 + d2); break;
			case '-':
				num.push_back(d1 - d2); break;
			case '*':
				num.push_back(d1 * d2); break;
			case '/':
				num.push_back(d1 / d2); break;
			}
		}
	}
	return num[0];
}