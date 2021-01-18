#pragma once
#include<iostream>
using namespace std;

class Neuron {
private:
	int Value;				//Store integer
	string Op;				//Store operation
	Neuron* RightNeuron;			//For linked list
	Neuron* DownNeuron;		//For linked list
public:
	Neuron() : Value(0), Op(""), RightNeuron(NULL), DownNeuron(NULL) {}			//Constructor 
	void SetValue(int value);																					//Set integer value
	void SetOp(string Operation);																		//Set operation value
	void SetRightNeuron(Neuron* NewNeuron);											//Set right node
	void SetDownNeuron(Neuron* NewNeuron);											//Set down node
	int getValue();																										//Get integer value
	string getOp();																									//Get operation
	Neuron* getRightNeuron();																			//Get right node
	Neuron* getDownNeuron();																			//Get down node
};

class LinkedList {
private:
	Neuron* HeadNode;													//Head node
public:
	LinkedList(): HeadNode(NULL){}						//Constructor
	void First_state();														//Set First state
	void Update_state();													//Update state
	void Final_state();														//Final state (circulate formula)
};

