/*********************************************************************
** File name:  Room1.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class 
*********************************************************************/

#include "Room1.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Room1::Room1()
{
	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "\n--------------------------------------------------\n";
	roomScript[0].text += "Ye find yeself in yon dungeon cell.  Ye remember \n";
	roomScript[0].text += "nothing of how you got here.  A sliver of light \n";
	roomScript[0].text += "shining through a crack in the wall reminds you of \n";
	roomScript[0].text += "that onet time your parents let you outside as a kid, \n";
	roomScript[0].text += "leaving you with a strong yearning to escapse. \n";
	roomScript[0].text += "Obvious exits are ";
	roomScript[1].text += "NORTH(1), ";
	roomScript[2].text += "SOUTH(2), ";
	roomScript[3].text += "and \nDENNIS(3).\n\n";
	roomScript[4].text += "What wouldst thou deau?\n";
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
		if (i < 4)
		{
			roomMenuChoice[i].interactionType = 1;
			roomMenuChoice[i].delFlg = 0;
		}

		else
		{
			roomMenuChoice[i].interactionType = 0;
			roomMenuChoice[i].delFlg = 1;
		}
	}
	
	roomOptions = 3;
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Room1::selectRoomOption(int x)
{
	// Exit type interaction
	switch(x)
	{
	case 1:
		cout << "You go NORTH.\n\n";
		return nextRoom[0];
	case 2:
		cout << "You go SOUTH.\n\n";
		return nextRoom[2];
	case 3:
		cout << "You go DENNIS.\n\n";
		return nextRoom[1];
	default:
		return NULL;
	}


	// Disposable interaction
	if (roomMenuChoice[x].interactionType == 2)
	{
		//
	}

	// Non-Disposable interaction
	if (roomMenuChoice[x].interactionType == 3)
	{
		//
	}
}