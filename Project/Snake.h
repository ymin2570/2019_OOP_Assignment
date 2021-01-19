#pragma once

class Snake {
public:
	Snake();
	~Snake();
	Snake *next;		//Next body of snake
	Snake *prev;		//Previous body of snake
	int xpos;				//Coordinates
	int ypos;
	int direct;				//Direction
};

class Food {
public:
	int xpos;				//Coordinates
	int ypos;
};

void SetSnake(Snake** SnakeHead);									//Make Snake
void Move(Snake* SnakeHead);											//Move Snake
void EatMove(Snake* SnakeHead);										//Move Snake that eats the food
bool BodyCoong(Snake* SnakeHead);								//Check that Snake's head hits the wall
bool WallCoong(Snake* SnakeHead);									//Check that Snake's head hits its body
bool Eat(Snake* SnakeHead, Food* food);						//When Snake eats the food
void SetFood(Snake* SnakeHead, Food** food);				//Make Food