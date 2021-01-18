#include<iostream>
using namespace std;

double Rectangle(int, int);
double Triangle(int, int);
double Diamond(int, int);

int main()
{
	int width, height;						//variable to save input
	double(*Figurearea[3]) (int, int) = { Rectangle, Triangle, Diamond };			//Function pointer array
	cout << ">>Width : ";			//Input
	cin >> width;
	cout << ">>Height : ";
	cin >> height;
	cout << endl << endl;

	cout << "Area of the rectangular : " << Figurearea[0](width, height) << endl;		//Call Rectangle function
	cout << "Area of the triangle : " << Figurearea[1](width, height) << endl;			//Call Triangle function
	cout << "Area of the diamond : " << Figurearea[2](width, height) << endl;		//Call Diamond function
	return 0;
}

double Rectangle(int width, int height)
{
	double rec;
	rec = (width * height);			//Calculate area
	return rec;
}

double Triangle(int width, int height)
{
	double tri;
	tri = (double)width * height / 2;		//Calculate area
	return tri;
}

double Diamond(int width, int height)
{
	double dia;
	dia = (double)width * height / 2;		//Calculate area
	return dia;
}