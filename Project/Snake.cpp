#include "stdafx.h"
#include "Snake.h"

Snake::Snake() {
	xpos = 0;
	ypos = 0;
	direct = 0;
	next = NULL;
	prev = NULL;
}
Snake::~Snake(){}

void SetSnake(Snake** SnakeHead) {
	Snake *temp;
	Snake *newbody;											//New body of Snake
	temp = (*SnakeHead);

	for (int i = 0; i < 3; i++) {
		if (temp == NULL) {									//Make head of the Snake
			newbody = new Snake();
			newbody->direct = 'A';						//Go left
			newbody->xpos = 13;							//Center of map
			newbody->ypos = 13;
			(*SnakeHead) = newbody;					//Store head value
			temp = newbody;
		}
		else {
			newbody = new Snake();
			newbody->direct = 'A';
			newbody->xpos = 13 + i;					//Right coordinate of head
			newbody->ypos = 13;
			temp->next = newbody;						//Link the body each other
			newbody->prev = temp;
			temp = newbody;
		}
	}
}
void Move(Snake* SnakeHead) {
	Snake *temp;
	Snake *Prev;											//Previous body
	temp = SnakeHead;
	Prev = NULL;

	while (temp->next != NULL) {			// Find tail node
		Prev = temp;
		temp = temp->next;
	}
	while (Prev != NULL) {						//Move all body except head
		temp->xpos = Prev->xpos;
		temp->ypos = Prev->ypos;
		Prev = Prev->prev;
		temp = temp->prev;
	}
	switch (temp->direct)							//Move head according to direction
	{
	case 'w':
	case 'W':
		temp->ypos -= 1;
		break;
	case 's':
	case 'S':
		temp->ypos += 1;
		break;
	case 'a':
	case 'A':
		temp->xpos -= 1;
		break;
	case 'd':
	case 'D':
		temp->xpos += 1;
		break;
	}
}
void EatMove(Snake* SnakeHead) {
	Snake *temp;
	Snake *Prev;											//Previous body
	temp = SnakeHead;
	Prev = NULL;
		
	while (temp->next != NULL) {			// Find tail node
		Prev = temp;
		temp = temp->next;
	}
	temp = temp->prev;							//Except for new body
	Prev = Prev->prev;

	while (Prev != NULL) {						//Move all body except head and new body
		temp->xpos = Prev->xpos;
		temp->ypos = Prev->ypos;
		Prev = Prev->prev;
		temp = temp->prev;
	}
	switch (temp->direct)							//Move head according to direction
	{
	case 'w':
	case 'W':
		temp->ypos -= 1;
		break;
	case 's':
	case 'S':
		temp->ypos += 1;
		break;
	case 'a':
	case 'A':
		temp->xpos -= 1;
		break;
	case 'd':
	case 'D':
		temp->xpos += 1;
		break;
	}
}
bool BodyCoong(Snake* SnakeHead) {
	Snake *temp;
	temp = SnakeHead->next;					//Right next body of head
	while (temp != NULL) {
		if (temp->xpos == SnakeHead->xpos && temp->ypos == SnakeHead->ypos)			//Head hits its body
			return true;
		temp = temp->next;
	}
	return false;
}
bool WallCoong(Snake* SnakeHead) {
	if (SnakeHead->xpos < 1 || SnakeHead->xpos>25 || SnakeHead->ypos < 1 || SnakeHead->ypos > 25) {			//Head go out of range
		return true;
	}
	else
		return false;
}
bool Eat(Snake* SnakeHead, Food* food) {
	Snake *newbody;												//New body
	Snake *temp;
	temp = SnakeHead;

	if (SnakeHead->xpos != food->xpos || SnakeHead->ypos != food->ypos)		//Doesn't eat food
		return false;

	else {
		while (temp->next != NULL) {			//Find tail
			temp = temp->next;
		}
		newbody = new Snake();
		newbody->direct = temp->direct;
		newbody->xpos = temp->xpos;					//Add new body in the coordinates of tail
		newbody->ypos = temp->ypos;
		temp->next = newbody;									//Link the body each other
		newbody->prev = temp;
		return true;
	}
}
void SetFood(Snake* SnakeHead, Food** food) {
	Snake *temp;
	temp = SnakeHead;
	(*food) = new Food();
	srand((unsigned int)time(NULL));
	(*food)->xpos = rand() % 25 + 1;				//Set food coordinates randomly
	(*food)->ypos = rand() % 25 + 1;

	while (temp != NULL) {
		if ((*food)->xpos == temp->xpos && (*food)->ypos == temp->ypos) {		//If food coordinate is matched with Snake's body
			(*food)->xpos = rand() % 25 + 1;
			(*food)->ypos = rand() % 25 + 1;
			temp = SnakeHead;
		}
		temp = temp->next;
	}
}