#pragma once
#include<iostream>
#include"Human.h"

class Human;
class Monster {
private:
	int health;
	int power;
	int row;
	int column;
	char index;
	Monster* prev;
	Monster* next;
public:
	Monster() {														//Constructor
		health = 20;
		power = 7;
		index = '\0';
		prev = NULL;
		next = NULL;
	};
	void action(Human *);										// Attack or move
	void Sethealth(int);											// Set health value
	void Setrow(int);												// Set row value
	void Setcolumn(int);										// Set column value
	void Setindex(char);											// Set index value
	void Setprev(Monster *);								// Set previous node
	void Setnext(Monster *);									// Set next node
	int gethealth();													// Get health value
	int getrow();														// Get row value
	int getcolumn();													// Get column value
	char getindex();													// Get index value
	Monster *getnext();											// Get next node
	Monster *getprev();											// Get previous node
};

