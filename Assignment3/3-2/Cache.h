#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include<iostream>
#include<string>//string, iterator
using namespace std;

class CacheNode {
private:
	string Word;								//Store the word
	int Timestamp;							//Store the timestamp
	CacheNode* NextNode;			//Store address of next node
public:
	CacheNode(): Word(""),Timestamp(0),NextNode(NULL) {}		//Constructor
	string getWord();													//get private variable Word
	void SetWord(string newWord);							//Set word
	int getTimestamp();														//get private variable Timestamp
	void SetTimestamp(int newTimestamp);					//Set Timestamp
	CacheNode *getNextNode();												//get private variable NextNode
	void SetNextNode(CacheNode *newNextNode);					//Set NextNode
};

class CacheManager {
private:
	int CacheNum;							//Number of Cache
	CacheNode* HeadNode;			//Address of the head node
	string Upper;								//Upper alphabets
	string Lower;								//Lower alphabets
public:
	CacheManager(): CacheNum(0),HeadNode(NULL),Upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),Lower("abcdefghijklmnopqrstuvwxyz") {}			//Constructor
	~CacheManager();													//Destructor
	void AddNode(string newWord, int Timestamp);		//Add node to last
	void ChangeTimestamp(int index, int Timestamp);		//Change timestamp
	void ChangeNode(int index, string newWord, int Timestamp);		//Change the new node to a node in the existing list
	int FindNode(string newWord);			//Search for a node with the value equal to newWord in the list
	int LRU();		//Find smallest timestamp and return its index
	void DeleteNode(int index);			//Delete node
	void DisplayList();			//Show list
	void Operation(string newWord, int Timestamp);			//Print out final using all of other  functions
};

#endif