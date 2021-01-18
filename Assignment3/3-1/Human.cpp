#include<iostream>
#include"Human.h"

void Human::Sethealth(int Health) {
	health = Health;
}
void Human::Setrow(int Row) {
	row = Row;
}
void Human::Setcolumn(int Column) {
	column = Column;
}
void Human::Setindex(int Index) {
	index = Index;
}
void Human::Setprev(Human *human) {
	prev = human;
}
void Human::Setnext(Human *human) {
	next = human;
}
int Human::gethealth() {
	return health;
}
int Human::getrow() {
	return row;
}
int Human::getcolumn() {
	return column;
}
int Human::getindex() {
	return index;
}
Human * Human::getnext() {
	return next;
}
Human * Human::getprev() {
	return prev;
}

void Human::action(Monster* monster) {
	if (monster->getcolumn() >= column - 1 && monster->getcolumn() <= column + 1) {		//First, consider column
		if (monster->getrow() == row) {																											//If row is same
			monster->Sethealth(monster->gethealth() - power);																	//Attack
		}
		else if (monster->getrow() == row - 1 || monster->getrow() == row + 1) {							//Second, consider row
			if (monster->getcolumn() == column) {																							//If column is same
				monster->Sethealth(monster->gethealth() - power);																//Attack
			}
			else {
				if (monster->getcolumn() == column - 1) {																				//If the target column is human column - 1
					if (column > 0)																																	//Range of column
						Setcolumn(column - 1);																												//Move 
				}
				else if (monster->getcolumn() == column + 1) {																		//If the target column is human column + 1
					if (column < 4)																																	//Range of column
						Setcolumn(column + 1);																												//Move 
				}
			}
		}
		else {
			if (monster->getcolumn() == column) {																					//If column is same
				if (monster->getrow() > row + 1) {																						//If the target row is higher than human row + 1
					if (row < 4)																																	//Range of row
						Setrow(row + 1);																													//Move 
				}
				else if (monster->getrow() < row - 1)																					//If the target row is lower than human row - 1
				{
					if (row > 0)																																	//Range of row
						Setrow(row - 1);																													//Move 
				}	
			}
			else {
				if (monster->getcolumn() == column - 1) {																		//If the target column is human column - 1
					if (column > 0)																															//Range of column													
						Setcolumn(column - 1);																										//Move
				}
				else if (monster->getcolumn() == column + 1) {																//If the target column is human column + 1
					if (column < 4)																															//Range of column	
						Setcolumn(column + 1);																										//Move
				}
			}
		}
	}
	else {
		if (monster->getcolumn() < column - 1) {																	//If the target column is lower than human column - 1
			if (column > 0)																													//Range of column	
				Setcolumn(column - 1);																								//Move
		}
		else if (monster->getcolumn() > column + 1) {															//If the target column is higher than human column + 1
			if (column < 4)																													//Range of column	
				Setcolumn(column + 1);																								//Move
		}
	}
}
void Archer::action(Monster* monster) {
	if (monster->getcolumn() >= column - 1 && monster->getcolumn() <= column + 1) {	//First, consider column
		if (monster->getrow() >= row - 1 && monster->getrow() <= row + 1) {							//Second, consider row
			monster->Sethealth(monster->gethealth() - power);																//Attack
		}
		else if (monster->getrow() == row - 2 || monster->getrow() == row + 2) {
			if (monster->getcolumn() == column) {																						//Attack range
				monster->Sethealth(monster->gethealth() - power);															//Attack
			}
			else {
				if (monster->getcolumn() == column - 1) {																		//The target column is lower than human column
					if (column > 0)
						Setcolumn(column - 1);																										//Move
				}
				else if (monster->getcolumn() == column + 1) {																//The target column is higher than human column
					if (column < 4)
						Setcolumn(column + 1);																										//Move
				}
			}
		}
		else {
			if (monster->getcolumn() == column) {																			//If column is same
				if (monster->getrow() > row + 2) {																				//The target row is higher than human row + 2
					if (row < 4)
						Setrow(row + 1);																											//Move
				}
				else if (monster->getrow() < row - 2) {																		//The target row is lower than human row - 2
					if (row > 0)
						Setrow(row - 1);																											//Move
				}
			}
			else {
				if (monster->getcolumn() == column - 1) {																//The target column is lower than human column
					if (column > 0)
						Setcolumn(column - 1);																								//Move
				}
				else if (monster->getcolumn() == column + 1) {														//The target column is higher than human column
					if (column < 4)
						Setcolumn(column + 1);																								//Move
				}
			}
		}
	}
	else if (monster->getcolumn() == column - 2 || monster->getcolumn() == column + 2) {
		if (monster->getrow() == row) {																									//Attack range
			monster->Sethealth(monster->gethealth() - power);															//Attack
		}
		else {
			if (monster->getcolumn() == column - 2) {																//The target column is lower than human column
				if (column > 0)
					Setcolumn(column - 1);																								//Move
			}
			else if (monster->getcolumn() == column + 2) {														//The target column is higher than human column
				if (column < 4)
					Setcolumn(column + 1);																								//Move
			}
		}
	}
	else {
		if (monster->getcolumn() > column + 2) {																//The target column is higher than human column
			if (column < 4)
				Setcolumn(column + 1);																							//Move
		}
		else if (monster->getcolumn() < column - 2) {														//The target column is lower than human column
			if (column > 0)
				Setcolumn(column - 1);																							//Move
		}
	}
}
void Warlock::action(Monster* monster) {
	Monster *target;
	int count = 0;
	double distance = 100;
	while (monster != NULL) {
		if (distance > sqrt(pow(monster->getrow() - row, 2) + pow(monster->getcolumn() - column, 2))) {			//Set target closest enemy
			target = monster;
			distance = sqrt(pow(monster->getrow() - row, 2) + pow(monster->getcolumn() - column, 2));
		}
		else if (distance == sqrt(pow(monster->getrow() - row, 2) + pow(monster->getcolumn() - column, 2))) {	//Set target lower index
			if (target->getindex() > monster->getindex()) {
				target = monster;
			}
		}
		if (sqrt(pow(monster->getrow() - row, 2) + pow(monster->getcolumn() - column, 2)) <= 1) {			//If enemy is in attack range
			if (count < 4) {																							//Can attack up to 4 monsters
				if (mana == true) {
					monster->Sethealth(monster->gethealth() - power);			//Attack
					count++;
				}
			}
		}
		monster = monster->getnext();
	}
	if (count == 0) {																														//If not attack anyone
		if (target->getcolumn() >= column - 1 && target->getcolumn() <= column + 1) {
			if (target->getrow() == row - 1 || target->getrow() == row + 1) {
				if (target->getcolumn() == column - 1) {												//Target column is lower than human column
					if (column > 0)
						Setcolumn(column - 1);																			//Move
				}
				else if (target->getcolumn() == column + 1) {										//Target column is higher than human column
					if (column < 4)
						Setcolumn(column + 1);																			//Move
				}
			}
			else if(target->getrow() != row) {
				if (target->getcolumn() == column) {
					if (target->getrow() > row + 1) {											//Target row is higher than human row + 1
						if (row < 4)
							Setrow(row + 1);																	//Move
					}
					else if (target->getrow() < row - 1)										//Target row is lower than human row - 1
					{
						if (row > 0)
							Setrow(row - 1);																	//Move
					}
				}
				else {
					if (target->getcolumn() == column - 1) {										//Target column is lower than human column
						if (column > 0)
							Setcolumn(column - 1);																	//Move
					}
					else if (target->getcolumn() == column + 1) {								//Target column is higher than human column
						if (column < 4)
							Setcolumn(column + 1);																	//Move
					}
				}
			}
		}
		else {
			if (target->getcolumn() < column - 1) {									//Target column is lower than human column - 1
				if (column > 0)
					Setcolumn(column - 1);															//Move
			}
			else if (target->getcolumn() > column + 1) {							//Target column is higher than human column + 1
				if (column < 4)
					Setcolumn(column + 1);															//Move
			}
		}
	}
	if (mana == true)													//Change mana value after action is over
		mana = false;
	else
		mana = true;
}
