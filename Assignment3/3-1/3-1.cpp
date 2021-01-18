#include"Humanlist.h"
#include"Monsterlist.h"
using namespace std;

int main()
{
	Monsterlist *monster = new Monsterlist();	//Monsterlist
	Humanlist *human = new Humanlist();		//Humanlist
	int round = 1, size1 = 0, size2 = 0;			//Variable of round and Store the number of instances in each list
	monster->Setcamp();									//Set both camp
	human->Setcamp();
	while (monster->getNum() > 0 && human->getNum() > 0) {				//Finished when one of camp has no instance
		char *arr1 = new char[human->getNum()];												//Dynamic allocate to save list's index
		char *arr2 = new char[monster->getNum()];
		arr1[0] = NULL;																										//Initialize
		arr2[0] = NULL;
		size1 = human->getNum();																				//Store the number of instances
		size2 = monster->getNum();
		human->Setarr(arr1);																							//Store all of indexes in the array
		monster->Setarr(arr2);
		cout << "#### Result of round " << round << " ####" << endl;		//Print out round message
		human->Action(monster);																				//Human's turn (doing Action)
		monster->Action(human);																				//Monster's turn (doing Action)
		if(human->getNum() > 0)																					//If there is instance in the list
			human->Showlist();																						//Show list
		else {
			cout << "<Human>" << endl;
		}
		if(monster->getNum() > 0)																				//If there is instance in the list
			monster->Showlist();																						//Show list
		else {
			cout << "<Monster>" << endl;
		}
		human->Check(arr1,size1);																				//Print out deleted instance
		monster->Check(arr2,size2);
		cout << endl;
		round++;
		delete[]arr1;																											//Delete
		delete[]arr2;
	}
	if (monster->getNum() == 0) {																			//If monster instance is 0
		cout << "#### Final result of battle ####" << endl;
		cout << "Human has been won" << endl;
	}
	else if (human->getNum() == 0) {																		//If human instance is 0
		cout << "#### Final result of battle ####" << endl;
		cout << "Human has been defeated" << endl;
	}
	return 0;
}