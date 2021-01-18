#pragma once
#include"Monster.h"

class Monster;
class Human {
protected:
	int health;
	int power;
	int row;
	int column;
	int index;
	Human* prev;
	Human* next;
public:
	Human():prev(NULL),next(NULL)  {}			// Constructor
	virtual void action(Monster*);							// Attack or move
	void Sethealth(int);												// Set health value
	void Setrow(int);													// Set row value
	void Setcolumn(int);											// Set column value
	void Setindex(int);												// Set index value
	void Setprev(Human*);										// Set previous node
	void Setnext(Human*);										// Set next node
	int gethealth();														// Get health value
	int getrow();															// Get row value
	int getcolumn();														// Get column value
	int getindex();															// Get index value
	Human *getnext();												// Get next node
	Human *getprev();												// Get previous node
};

class Peasant_Army : public Human			//Inherited from the Human Class
{
public:
	Peasant_Army() {					//Constructor
		health = 5;
		power = 5;
		prev = NULL;
		next = NULL;
	};
};

class Sword_Master : public Human			//Inherited from the Human Class
{
public:
	Sword_Master() {								//Constructor
		health = 10;
		power = 10;
		prev = NULL;
		next = NULL;
	};
};

class Archer : public Human			//Inherited from the Human Class
{
public:
	Archer() {						//Constructor
		health = 7;
		power = 10;
		prev = NULL;
		next = NULL;
	};
	void action(Monster*);			//Overriding
};

class Warlock : public Human			//Inherited from the Human Class
{
protected:
	bool mana;			//Not inherited
public:
	Warlock() {			//Constructor
		health = 3;
		power = 10;
		prev = NULL;
		next = NULL;
		mana = true;
	};
	void action(Monster*);		//Overriding
};
