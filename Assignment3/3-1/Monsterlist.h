#pragma once
#include"Humanlist.h"
#include"Monster.h"
class Humanlist;
class Monsterlist {
private:
	Monster *Head;
	int Num;
public:
	Monsterlist() :Head(NULL), Num(0) {}									//Constructor
	int getNum();																					//Get Num value
	Monster *getHead();																	//Get Head node
	void Setarr(char *arr);																	//Set array
	void Setcamp();																				//Set camp
	void Showlist();																				//Show list of camp
	void Deletelist();																			//Delete node in list that health is  lower than or equal to 0
	void Action(Humanlist *human);												//Set the target and doing action function and delete
	void Check(char *arr, int size);													//Check if there is a deleted node and print out if it is
};
