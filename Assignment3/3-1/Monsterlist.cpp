#include<iostream>
#include<cmath>//sqrt,pow
#include"Monsterlist.h"
using namespace std;

int Monsterlist::getNum() {

	return Num;
}
Monster *Monsterlist::getHead() {
	return Head;
}

void Monsterlist::Setarr(char *arr) {
	Monster *current;
	current = Head;
	for (int i = 0; i < Num; i++) {
		arr[i] = current->getindex();			//Save current index into arr
		current = current->getnext();
	}
}
void Monsterlist::Setcamp() {
	Monster *monster_a = new Monster(), *monster_b = new Monster(), *monster_c = new Monster(), *monster_d = new Monster(), *monster_e = new Monster();
	Head = monster_a;
	monster_a->Setindex('A');							//Set Each instances' index
	monster_b->Setindex('B');
	monster_c->Setindex('C');
	monster_d->Setindex('D');
	monster_e->Setindex('E');
	monster_a->Setrow(0);								//Set Each instances' coordinate
	monster_b->Setrow(1);
	monster_c->Setrow(2);
	monster_d->Setrow(3);
	monster_e->Setrow(4);
	monster_a->Setcolumn(4);
	monster_b->Setcolumn(4);
	monster_c->Setcolumn(4);
	monster_d->Setcolumn(4);
	monster_e->Setcolumn(4);
	monster_a->Setnext(monster_b);				//Set double linked list
	monster_b->Setnext(monster_c);
	monster_c->Setnext(monster_d);
	monster_d->Setnext(monster_e);
	monster_b->Setprev(monster_a);
	monster_c->Setprev(monster_b);
	monster_d->Setprev(monster_c);
	monster_e->Setprev(monster_d);
	Num += 5;															//Save the number of instances
}
void Monsterlist::Showlist() {
	Monster *current;
	current = Head;
	cout << "<Monster>" << endl;
	while (current != NULL)
	{
		cout << current->getindex() << endl;			//Print out instances' index
		current = current->getnext();
	}
}
void Monsterlist::Deletelist() {
	Monster *current, *prev, *next;
	current = Head;
	prev = NULL;
	next = current->getnext();
	while (next != NULL) {
		if (current->gethealth() <= 0) {				//Delete condition is matched
			if (prev == NULL) {
				Head = next;
				next->Setprev(NULL);							//Disconnect the connection 
				current->Setnext(NULL);
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
void Monsterlist::Action(Humanlist *human) {
	Human *target, *current_h;
	Monster *current;
	double distance;				//Variable for store distance to compare
	current = Head;
	current_h = human->getHead();

	while (current != NULL) {
		if (human->getNum() != 0) {																				//If instance is available
			distance = 100;
			current_h = human->getHead();
			while (current_h != NULL) {
				if (distance > sqrt(pow(current_h->getrow() - current->getrow(), 2) + pow(current_h->getcolumn() - current->getcolumn(), 2))) {			//Set target closest enemy
					target = current_h;
					distance = sqrt(pow(current_h->getrow() - current->getrow(), 2) + pow(current_h->getcolumn() - current->getcolumn(), 2));
				}
				else if (distance == sqrt(pow(current_h->getrow() - current->getrow(), 2) + pow(current_h->getcolumn() - current->getcolumn(), 2))) {	//Set target lower index
					if (target->getindex() > current_h->getindex()) {
						target = current_h;
					}
				}
				current_h = current_h->getnext();		//Consider next node
			}
			current->action(target);								//Convey target
			human->Deletelist();									//Delete if there is something that meets the death condition
			current = current->getnext();					//Consider next node
		}
		else 
			return;
	}
}
void Monsterlist::Check(char *arr, int size) {
	Monster *current;
	bool check;								//Variable for check if instance is removed
	for (int i = 0; i < size; i++) {
		check = false;
		current = Head;
		if (Num != 0) {																//If instance is available
			while (current != NULL) {
				if (arr[i] == current->getindex()) {
					check = true;														//If same index is exist
					break;																	//Break While loop
				}
				else {
					current = current->getnext();
				}
			}
			if (check == false) {													//There is no index in the list
				cout << "Monster " << arr[i] << " has died" << endl;	//Print out message
			}
		}
		else {																					//No instance is in the list
			cout << "Monster " << arr[i] << " has died" << endl;
		}
	}
}