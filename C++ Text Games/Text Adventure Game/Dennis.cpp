/*********************************************************************
** File name: Dennis.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: derived from Room class
*********************************************************************/

#include "Dennis.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Dennis::Dennis()
{
	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "--------------------------------------------------\n";
	roomScript[0].text += "Ye arrive at DENNIS";
	roomScript[1].text += "(1)";
	roomScript[2].text += ".  DENNIS is pacing around \nat a furious rate!\n";
	roomScript[4].text += "\nObvious exits are NOT DENNIS(2). ";
	roomScript[4].text += "\n\nWhat wouldst thou deau?\n";
	roomScript[4].text += "--------------------------------------------------\n\n";
	roomScript[4].text += "Enter Option: ";

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			roomScript[i].delFlg = 0;
		}

		else
		{
			roomScript[i].delFlg = 1;
		}
	}

	// Set menu options
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			roomMenuChoice[i].interactionType = 2;
			roomMenuChoice[i].delFlg = 0;
		}

		else if (i == 1)
		{
			roomMenuChoice[i].interactionType = 1;
			roomMenuChoice[i].delFlg = 0;
		}

		else if (i == 2)
		{
			roomMenuChoice[i].interactionType = 2;
			roomMenuChoice[i].delFlg = 1;
		}

		else
		{
			roomMenuChoice[i].interactionType = 0;
			roomMenuChoice[i].delFlg = 1;
		}
	}

	roomOptions = 3;



	roomItem[1].setItemName("COOL BRICK");
	roomItem[1].setDelFlg(0);

	roomItem[3].setItemName("DENNIS");
	roomItem[3].setDelFlg(0);
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Dennis::selectRoomOption(int x)
{
	switch (x)
	{
	case 1:
		cout << "Ye engage DENNIS in casual conversation.  He informs\n"
			<< "you this is not a good time for casual conversation,\n"
			<< "and that he needs to train for his upcoming competition \n"
			<< "in the world's great gathering of people who pace about \n"
			<< "nervously. Tiring of the conversation, he hands ye a \n"
			<< "COOL BRICK and tells you to come back when you've gotten \n"
			<< "more interesting.\n\n";

		roomScript[1].delFlg = 1;
		roomMenuChoice[0].delFlg = 1;

		roomScript[3].text += "DENNIS is currently ignoring you. ";

		return NULL;
			
	case 2:
		cout << "You go NOT DENNIS.\n\n";
		return nextRoom[3];

	case 3:
		cout << "DENNIS has grown a new affection for you with your \n"
			<< "change in status of being on fire! You tell him about \n"
			<< "the DUNGEON CLERK and ask if he knows the password.  \n"
			<< "DENNIS says not to worry and he'll follow you to the \n"
			<< "reception desk.\n\n";

		roomScript[2].text.clear();
		roomScript[3].text.clear();
		roomMenuChoice[3].delFlg = 1;

		return NULL;
	}

}


/*********************************************************************
*						   getIsOnFire
*********************************************************************/
bool Dennis::getIsOnFire()
{
	return isOnFire;
}

/*********************************************************************
*						   setWithDennis
*********************************************************************/
void Dennis::setIsOnFire(bool x)
{
	isOnFire = x;
}

/*********************************************************************
*							 updateDennis
*********************************************************************/
void Dennis::updateDennis()
{
	roomScript[3].text.clear();

	roomScript[3].text += "You've caught DENNIS'S(3) attention!\n";
	roomMenuChoice[2].delFlg = 0;
}