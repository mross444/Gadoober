/*********************************************************************
** File name:  Room5.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#include "Room5.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Room5::Room5()
{
	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "--------------------------------------------------\n";
	roomScript[0].text += "Sweet Freedom! The air smells nice - like a crisp \n";
	roomScript[0].text += "Spring morning, mixed in with burning wool and your \n";
	roomScript[0].text += "flesh. The ground feels less hard than you are used \n";
	roomScript[0].text += "to. Actually, there is no ground at all.  It suddenly \n";
	roomScript[0].text += "comes back to you that the dungeon was on top of a \n";
	roomScript[0].text += "cliff.  Obvious exits are NO EXITS(1)\n\n";
	roomScript[0].text += "What wouldst thou deau?\n";
	roomScript[0].text += "--------------------------------------------------\n\n";
	roomScript[0].text += "Enter Option: ";

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
	roomMenuChoice[0].interactionType = 3;
	roomMenuChoice[0].delFlg = 0;

	roomOptions = 1;
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Room5::selectRoomOption(int x)
{
	return NULL;
}