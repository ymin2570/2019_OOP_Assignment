#include<iostream>
#include"Monster.h"


void Monster::Sethealth(int Health) {
	health = Health;
}
void Monster::Setrow(int Row) {
	row = Row;
}
void Monster::Setcolumn(int Column) {
	column = Column;
}
void Monster::Setindex(char Index) {
	index = Index;
}
void Monster::Setprev(Monster *monster) {
	prev = monster;
}
void Monster::Setnext(Monster *monster) {
	next = monster;
}
int Monster::gethealth() {
	return health;
}
int Monster::getrow() {
	return row;
}
int Monster::getcolumn() {
	return column;
}
char Monster::getindex() {
	return index;
}
Monster * Monster::getnext() {
	return next;
}
Monster * Monster::getprev() {
	return prev;
}

void Monster::action(Human* human) {
	if (human->getcolumn() >= column - 1 && human->getcolumn() <= column + 1) {
		if (human->getrow() >= row - 1 && human->getrow() <= row + 1) {								//Attack range
			human->Sethealth(human->gethealth() - power);																	//Attack
		}
		else {
			if (human->getrow() > row + 1 || human->getrow() < row - 1) {
				if (human->getcolumn() == column - 1) {								//Target column is lower than human column
					if (column > 0)
						Setcolumn(column - 1);															//Move
				}
				else if (human->getcolumn() == column + 1) {					//Target column is higher than human column
					if (column < 4)
						Setcolumn(column + 1);															//Move
				}
				else {
					if (human->getrow() > row + 1) {									//Target row is higher than human row + 1
						if (row < 4)
							Setrow(row + 1);															//Move
					}
					else if (human->getrow() < row - 1) {							//Target row is lower than human row - 1
						if (row > 0)
							Setrow(row - 1);															//Move
					}
				}
			}
		}
	}
	else {
		if (human->getcolumn() > column + 1) {							//Target column is higher than human column + 1
			if (column < 4)
				Setcolumn(column + 1);														//Move
		}
		else if (human->getcolumn() < column - 1) {						//Target column is lower than human column - 1
			if (column > 0)
				Setcolumn(column - 1);														//Move
		}
	}
}