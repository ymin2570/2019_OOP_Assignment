#include<iostream>
#include<cmath>//sqrt,pow
#include"Humanlist.h"
using namespace std;

int Humanlist::getNum() {
	return Num;
}
Human *Humanlist::getHead() {
	return Head;
}

void Humanlist::Setarr(char *arr) {
	Human *current;
	current = Head;
	for (int i = 0; i < Num; i++) {
		arr[i] = (char)current->getindex();			//Save current index into arr
		current = current->getnext();
	}
}
void Humanlist::Setcamp() {	
	Peasant_Army *human1 = new Peasant_Army();
	Sword_Master *human2 = new Sword_Master(), *human3 = new Sword_Master();
	Archer *human4 = new Archer();
	Warlock *human5 = new Warlock();
	Head = human1;
	human1->Setindex(1);						//Set Each instances' index
	human2->Setindex(2);
	human3->Setindex(3);
	human4->Setindex(4);
	human5->Setindex(5);
	human1->Setrow(0);							//Set Each instances' coordinate
	human2->Setrow(1);
	human3->Setrow(2);
	human4->Setrow(3);
	human5->Setrow(4);
	human1->Setcolumn(0);
	human2->Setcolumn(0);
	human3->Setcolumn(0);
	human4->Setcolumn(0);
	human5->Setcolumn(0);
	human1->Setnext(human2);					//Set double linked list
	human2->Setnext(human3);
	human3->Setnext(human4);
	human4->Setnext(human5);
	human2->Setprev(human1);
	human3->Setprev(human2);
	human4->Setprev(human3);
	human5->Setprev(human4);
	Num += 5;													//Save the number of instances
}
void Humanlist::Showlist() {
	Human *current;
	current = Head;
	cout << "<Human>" << endl;
	while (current != NULL)
	{
		cout << current->getindex() << endl;				//Print out instances' index
		current = current->getnext();
	}
}
void Humanlist::Deletelist() {
	Human *current, *prev, *next;
	current = Head;
	prev = NULL;
	next = current->getnext();
	while (next != NULL) {
		if (current->gethealth() <= 0) {				//Delete condition is matched
			if (prev == NULL) {
				Head = next;
				next->Setprev(NULL);							//Disconnect the connection 
				//current->Setnext(NULL);
				delete current;											//Delete
				Num--;															//Update the number of instances in the list
				current = next;											//Consider the next node
				prev = NULL;
				next = current->getnext();
			}
			else {
				prev->Setnext(next);								//Connect with other node
				current->Setprev(NULL);						//Disconnect the connection
				current->Setnext(NULL);
				next->Setprev(prev);
				delete current;											//Delete
				Num--;
				current = next;											//Consider the next node
				next = current->getnext();
			}
		}
		else {
			prev = current;												//Consider the next node
			current = current->getnext();
			next = current->getnext();
		}
	}
	if (current->gethealth() <= 0) {				//Delete condition is matched
		if (prev == NULL) {
			delete current;										//Delete
			Num--;
		}
		else {
			prev->Setnext(NULL);
			current->Setprev(NULL);
			delete current;										//Delete
			Num--;
		}
	}
}
void Humanlist::Action(Monsterlist *monster) {
	Monster *target, *current_m;
	Human *current;
	double distance;			//Variable for store distance to compare
	current = Head;
	current_m = monster->getHead();

	while (current != NULL) {
		if (monster->getNum() != 0) {																				//If instance is available
			distance = 100;
			current_m = monster->getHead();
			while (current_m != NULL) {
				if (distance > sqrt(pow(current_m->getrow() - current->getrow(), 2) + pow(current_m->getcolumn() - current->getcolumn(), 2))) {			//Set target closest enemy
					target = current_m;
					distance = sqrt(pow(current_m->getrow() - current->getrow(), 2) + pow(current_m->getcolumn() - current->getcolumn(), 2));
				}
				else if (distance == sqrt(pow(current_m->getrow() - current->getrow(), 2) + pow(current_m->getcolumn() - current->getcolumn(), 2))) {	//Set target lower index
					if (target->getindex() > current_m->getindex()) {
						target = current_m;
					}
				}
				current_m = current_m->getnext();		//Consider next node
			}
			if (current->getindex() == 5) {					//If instance is Warlock
				current_m = monster->getHead();
				current->action(current_m);					//Convey monsterlist's Head
			}
			else {
				current->action(target);								//Convey target
			}
			monster->Deletelist();									//Delete if there is something that meets the death condition
			current = current->getnext();						//Consider next node
		}
		else
			return;
	}
}
void Humanlist::Check(char *arr, int size) {
	Human *current;
	bool check;								//Variable for check if instance is removed
	for (int i = 0; i < size; i++) {
		check = false;
		current = Head;
		if (Num != 0) {																//If instance is available
			while (current != NULL) {
				if ((int)arr[i] == current->getindex()) {
					check = true;														//If same index is exist
					break;																	//Break While loop
				}
				else {
					current = current->getnext();
				}
			}
			if (check == false) {													//There is no index in the list
				cout << "Human " << (int)arr[i] << " has died" << endl;	//Print out message
			}
		}
		else {																					//No instance is in the list
			cout << "Human " << (int)arr[i] << " has died" << endl;
		}
	}
}