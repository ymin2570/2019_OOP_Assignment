#include"Elevator.h"
Elevator::Elevator() {};
Elevator::~Elevator() {};
void Elevator::Init()		//Function declaration in public of class
{
	E_floor = 1;								//Initialize
	E_upstairs = 0;
	E_downstairs = 0;
	E_time = 0;
}
void Elevator::Up(int floor)						//Declare Up function
{
	if (floor > 0 && floor<11 && floor > E_floor)				//range of floor and floor condition
	{
		E_upstairs += floor - E_floor;
		E_time += (floor - E_floor) / 2;				//Calculate E_time
		E_floor = floor;
		cout << "It is on the " << E_floor << " floor." << endl << endl;
	}
	else
		cout << "You can't go up to " << floor << " floor." << endl << endl;
}
void Elevator::Down(int floor)						//Declare Down function
{
	if (floor > 0 && floor < 11 && floor < E_floor)				//range of floor and floor condition
	{
		E_downstairs += E_floor - floor;
		E_time += (E_floor - floor) / 2;			//Calculate E_time
		E_floor = floor;
		cout << "It is on the " << E_floor << " floor." << endl << endl;
	}
	else
		cout << "You can't go down to " << floor << " floor." << endl << endl;
}
void Elevator::ShowInfo()							//Show variables in private of class
{
	cout << "Total upstairs: " << E_upstairs << endl;
	cout << "Total downstairs: " << E_downstairs << endl;
	cout << "Total time: " << E_time << endl;
}
int main()
{
	Elevator el;				//Declare class variable
	el.Init();					//call functions
	el.Up(7);
	el.Down(3);
	el.Down(5);
	el.Down(1);
	el.ShowInfo();
	return 0;
}