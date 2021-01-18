#include"Cache.h"

string CacheNode::getWord() {
	return Word;
}
int CacheNode::getTimestamp() {
	return Timestamp;
}
CacheNode* CacheNode::getNextNode() {
	return NextNode;
}
void CacheNode::SetWord(string newWord) {
	Word = newWord;
}
void CacheNode::SetTimestamp(int newTimestamp) {
	Timestamp = newTimestamp;
}
void CacheNode::SetNextNode(CacheNode* newNextNode) {
	NextNode = newNextNode;
}

void CacheManager::AddNode(string newWord, int Timestamp) {
	CacheNode* current, *previous, *node;
	if ((node = new CacheNode()) == NULL)
		return;

	node->SetWord(newWord);			//Make new node and initialize
	node->SetTimestamp(Timestamp);
	current = HeadNode;
	previous = NULL;

	while (current != NULL) {			//Find end of linkedlist
		previous = current;
		current = current->getNextNode();
	}
	if (previous == NULL) {				//If there is no node in list
		node->SetNextNode(HeadNode);		//Add it to last
		HeadNode = node;
	}
	else {													//Add it to last
		previous->SetNextNode(node);
		node->SetNextNode(current);
	}
	CacheNum++;
	return;
}
void CacheManager::ChangeTimestamp(int index, int Timestamp) {
	CacheNode *current;
	if (CacheNum < index)
		return;
	current = HeadNode;
	while (index > 0) {							//Find the node at the index
		current = current->getNextNode();
		index--;
	}
	current->SetTimestamp(Timestamp);		//Change that node's timestamp
}
void CacheManager::ChangeNode(int index, string newWord, int Timestamp) {
	CacheNode *current, *previous, *node;
	if (CacheNum < index)
		return;
	if ((node = new CacheNode()) == NULL)
		return;

	node->SetWord(newWord);						//Set new node
	node->SetTimestamp(Timestamp);
	current = HeadNode;
	previous = NULL;

	while (index > 0) {										//Find the node at the index
		previous = current;
		current = current->getNextNode();
		index--;
	}
	if (previous == NULL) {
		node->SetNextNode(current->getNextNode());		//Connect with new node
		HeadNode = node;
	}
	else {
		previous->SetNextNode(node);
		node->SetNextNode(current->getNextNode());		//Connect with new node
	}
	delete current;											//Delete node
}
int CacheManager::FindNode(string newWord) {
	CacheNode *current;
	string word1, word2, temp;		//String for case-insensitive
	bool find = false;							//variable for compare strings
	int index, key, key_timestamp;
	key = -1;
	key_timestamp = 1000;
	index = 0;
	current = HeadNode;
	while (current != NULL)
	{
		temp = current->getWord();
		string::iterator i = temp.begin();
		string::iterator j = newWord.begin();
		for (; i != temp.end(); i++)									//Copy the word of the node in the linked list for case-insensitive
		{
			if (Upper.find(*i) != string::npos) {
				word1 += *i;
				continue;
			}
			if (Lower.find(*i) != string::npos) {
				word1 += *i - 32;
				continue;
			}
		}
		for (; j != newWord.end(); j++)									//Copy the newword for case-insensitive
		{
			if (Upper.find(*j) != string::npos) {
				word2 += *j;
				continue;
			}
			if (Lower.find(*j) != string::npos) {
				word2 += *j - 32;
				continue;
			}
		}
		if (word1 == word2)			//Compare words in case-insensitve
			find = true;

		if (find == true) {						//If newword is in the linked list
			if (current->getTimestamp() < key_timestamp)
			{
				key = index;																	//Store its index and timestamp
				key_timestamp = current->getTimestamp();
			}
		}
		index++;
		current = current->getNextNode();
		find = false;								//Reset
		word1 = "";	
		word2 = "";
		temp = "";
	}
	return key;
}
int CacheManager::LRU() {
	CacheNode *current;
	int key, key_timestamp, index;
	key = -1;
	index = 0;
	key_timestamp = 1000;
	current = HeadNode;
	while (current != NULL) {
		if (current->getTimestamp() < key_timestamp) {			//Save smallest timestamp and its index
			key = index;
			key_timestamp = current->getTimestamp();
		}
		index++;
		current = current->getNextNode();
	}
	return key;				//return LRU index
}
void CacheManager::DeleteNode(int index) {
	CacheNode *current, *previous;
	if (CacheNum <= index || index < 0)
		return;
	current = HeadNode;
	previous = NULL;
	while (index > 0) {							//Find the node at the index
		previous = current;
		current = current->getNextNode();
		index--;
	}
	if (previous == NULL)
		HeadNode = current->getNextNode();
	else
		previous->SetNextNode(current->getNextNode());

	delete current;								//Delete

	return;
}
void CacheManager::DisplayList() {
	CacheNode *current;
	current = HeadNode;
	while (current != NULL) {
		cout << current->getWord() << ": " << current->getTimestamp() << "    ";			//Print out node's word and timestamp
		current = current->getNextNode();
	}
	cout << endl;
}
void CacheManager::Operation(string newWord, int Timestamp) {
	if (CacheNum < 5) {
		if (FindNode(newWord) == -1) {				//No same word exist
			AddNode(newWord, Timestamp);			//Add
			cout << "Miss ";
		}
		else {
			ChangeTimestamp(FindNode(newWord), Timestamp);		//Change timestamp
			cout << "Hit  ";
		}
	}
	else {
		if (FindNode(newWord) == -1) {			//No same word exist
			ChangeNode(LRU(), newWord, Timestamp);			//Change smallest timestamp node with new node
			cout << "Miss ";
		}
		else {
			ChangeTimestamp(FindNode(newWord), Timestamp);		//Change timestamp
			cout << "Hit  ";
		}
	}	
	DisplayList();					//Display list
}
CacheManager::~CacheManager() {							//Destructor
	for (int i = 0, size = CacheNum; i < size; i++)
		DeleteNode(0);
}
