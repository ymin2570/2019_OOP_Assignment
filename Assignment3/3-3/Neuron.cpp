#include"Neuron.h"
#include<string>
#include<cstdlib>


void Neuron::SetValue(int value) {
	Value = value;
}
void Neuron::SetOp(string Operation) {
	Op = Operation;
}
void Neuron::SetRightNeuron(Neuron* NewNeuron) {
	RightNeuron = NewNeuron;
}
void Neuron::SetDownNeuron(Neuron* NewNeuron) {
	DownNeuron = NewNeuron;
}
int Neuron::getValue() {
	return Value;
}
string Neuron::getOp() {
	return Op;
}
Neuron* Neuron::getRightNeuron() {
	return RightNeuron;
}
Neuron* Neuron::getDownNeuron() {
	return DownNeuron;
}

void LinkedList::First_state() {
	Neuron *Node1, *Node2, *Node3, *Node4, *Node5, *Node6, *Node7, *Node8, *Node9;
	if ((Node1 = new Neuron()) == NULL)
		return;
	if ((Node2 = new Neuron()) == NULL)
		return;
	if ((Node3 = new Neuron()) == NULL)
		return;
	if ((Node4 = new Neuron()) == NULL)
		return;
	if ((Node5 = new Neuron()) == NULL)
		return;
	if ((Node6 = new Neuron()) == NULL)
		return;
	if ((Node7 = new Neuron()) == NULL)
		return;
	if ((Node8 = new Neuron()) == NULL)
		return;
	if ((Node9 = new Neuron()) == NULL)
		return;
	Node1->SetValue(9);				//Set Node1
	Node1->SetOp("add");
	Node2->SetValue(0);				//Set Node2
	Node2->SetOp("mul");
	Node3->SetValue(6);				//Set Node3
	Node3->SetOp("");
	Node4->SetValue(5);				//Set Node4
	Node4->SetOp("div");
	Node5->SetValue(3);				//Set Node5
	Node5->SetOp("sub");
	Node6->SetValue(2);				//Set Node6
	Node6->SetOp("");
	Node7->SetValue(1);				//Set Node7
	Node7->SetOp("add");
	Node8->SetValue(7);				//Set Node8
	Node8->SetOp("div");
	Node9->SetValue(4);				//Set Node9
	Node9->SetOp("");
	Node1->SetRightNeuron(Node2);			//Connect each node according to the figure in question
	Node2->SetRightNeuron(Node3);
	Node4->SetRightNeuron(Node5);
	Node5->SetRightNeuron(Node6);
	Node7->SetRightNeuron(Node8);
	Node8->SetRightNeuron(Node9);
	Node1->SetDownNeuron(Node4);
	Node4->SetDownNeuron(Node7);
	HeadNode = Node1;			//Set HeadNode
}
void LinkedList::Update_state() {
	srand(1);										//For disconnect randomly
	int repeat = 0;								//Variable to determine how many neurons are in a row
	Neuron *Layer1, *current, *deleteNeuron;
	int ConnBreak;							//Probability of disconnecting 
	Layer1 = HeadNode;
	current = Layer1;
	while (current->getRightNeuron() != NULL)
	{
		ConnBreak = rand() % 10;			//Specify the probability of disconnection
		if (ConnBreak == 0)					//If connection is broken
		{
			deleteNeuron = current->getRightNeuron();
			if (deleteNeuron->getRightNeuron() != NULL)			//Delete even the node behind the disconnected node
			{
				deleteNeuron = deleteNeuron->getRightNeuron();
				delete deleteNeuron;
				deleteNeuron = current->getRightNeuron();
				delete deleteNeuron;
			}
			else
				delete deleteNeuron;														//Delete the disconnected node

			current->SetRightNeuron(NULL);
			return;																						//Terminate function if connection is disconnected
		}
		else
		{
			current = current->getRightNeuron();							//Next node in same row
			repeat++;
		}
	}
	if (repeat < 2) {											//No three neurons in a row
		for (int i = 0; i < repeat; i++) {
			ConnBreak = rand() % 10;				//Discard the disconnect probability of a disconnected neuron
		}
	}
	for (int i = 0; i < 2; i++)
	{
		repeat = 0;
		Layer1 = Layer1->getDownNeuron();								//Go down row
		current = Layer1;
		while (current->getRightNeuron() != NULL)					//Same with the code above
		{
			ConnBreak = rand() % 10;
			if (ConnBreak == 0)
			{
				deleteNeuron = current->getRightNeuron();
				if (deleteNeuron->getRightNeuron() != NULL)
				{
					deleteNeuron = deleteNeuron->getRightNeuron();
					delete deleteNeuron;
					deleteNeuron = current->getRightNeuron();
					delete deleteNeuron;
				}
				else
					delete deleteNeuron;

				current->SetRightNeuron(NULL);
				return;
			}
			else
			{
				current = current->getRightNeuron();
				repeat++;
			}
		}
		if (repeat < 2) {
			for (int i = 0; i < repeat; i++) {
				ConnBreak = rand() % 10;
			}
		}
	}
	return;
}
void LinkedList::Final_state() {
	Neuron *Layer1, *previous, *current;		//Layer1 makes it easier to access the nodes in each row
	int result = 0;									//variable to store calculated value
	Layer1 = HeadNode;
	current = Layer1;
	previous = NULL;
	for (int i = 0; i < 3; i++)				//Update state 3 times
		Update_state();

	for (int i = 0; i < 3; i++)
	{
		while (current != NULL)
		{
			if (previous == NULL)
			{
				result += current->getValue();						//Store the value of the first node into result variable
				cout << current->getValue();
				previous = current;
				current = current->getRightNeuron();			//Consider next node
			}
			else {
				if (previous->getOp() == "add")					//Consider previous node's operation
				{
					result = result + current->getValue();		//Store calculated value on Op in result
					cout << " + " << current->getValue();	//Print out operator according to the Op value
				}
				else if (previous->getOp() == "sub")
				{
					result = result - current->getValue();
					cout << " - " << current->getValue();
				}
				else if (previous->getOp() == "mul")
				{
					result = result * current->getValue();
					cout << " * " << current->getValue();
				}
				else if (previous->getOp() == "div")
				{
					result = result / current->getValue();
					cout << " / " << current->getValue();
				}
				previous = current;
				current = current->getRightNeuron();			//Next node in same row
			}
		}
		cout << " = " << result;												//Print out the calculated value that stored in result variable
		result = 0;
		if (Layer1->getDownNeuron() != NULL) {
			Layer1 = Layer1->getDownNeuron();				//Move layer1 to the next row
			current = Layer1;
			previous = NULL;
			cout << endl;
		}
	}
}