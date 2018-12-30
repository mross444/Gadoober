/*********************************************************************
** File name:  Room3.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#include "Room3.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Room3::Room3()
{
	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "--------------------------------------------------\n";
	roomScript[0].text += "Ye find yeself in a guard room.  The coast looks \n";
	roomScript[0].text += "clear.  Across the hall to the SOUTH (1) is what \n";
	roomScript[0].text += "appears to be the reception desk.  The wall here \n";
	roomScript[0].text += "has some CRUDE SPEARS(2) bolted to a rack.\n";
	roomScript[1].text += "Oh, wait - there's an ANGRY GUARD (3) here!! He's \n";
	roomScript[1].text += "swinging his spiky mace at you!!\n";
	roomScript[2].text += "Back to the NORTH(4) is your dungeon cell.\n\n";
	roomScript[2].text += "What wouldst thou deau?\n";
	roomScript[2].text += "--------------------------------------------------\n\n";
	roomScript[2].text += "Enter Option: ";

	for (int i = 0; i < 10; i++)
	{
		if (i < 3)
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
		if (i == 0 || i == 3)
		{
			roomMenuChoice[i].interactionType = 1;
			roomMenuChoice[i].delFlg = 0;
		}

		else if (i == 1)
		{
			roomMenuChoice[i].interactionType = 3;
			roomMenuChoice[i].delFlg = 0;
		}

		else if (i == 2)
		{
			roomMenuChoice[i].interactionType = 3;
			roomMenuChoice[i].delFlg = 0;
		}

		else 
		{
			roomMenuChoice[i].interactionType = 0;
			roomMenuChoice[i].delFlg = 1;
		}
	}

	roomOptions = 4;
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Room3::selectRoomOption(int x)
{
	switch (x)
	{
	case 1:
		if (roomMenuChoice[2].delFlg == 0)
		{
			cout << "The ANGRY GUARD is in the way!\n\n";
			return NULL;
		}
		else
		{
			cout << "You go SOUTH.\n\n";
			return nextRoom[2];
		}

	case 2:
		cout << "You try to take a CRUDE SPEAR, though unfortunately they \n"
			<< "are indeed bolted to the rack.\n\n";

		return NULL;

	case 3:
		if (hasBrick)
		{
			cout << "You show the guard your COOL BRICK! The guard is still \n"
				<< "really mad at you, though he is absoultely mesmerized by \n"
				<< "the COOL BRICK. With a change of heart, the guard decides \n"
				<< "to give up his spiky mace swinging days and become a brick \n"
				<< "layer.\n\n";

			roomMenuChoice[2].delFlg = 1;
			roomScript[1].delFlg = 1;
		}
		else
		{
			cout << "You consider taking on the guard, but think better of it. \n"
				<< "It's still too early in the game to die!\n\n";
		}

		return NULL;

	case 4:
		cout << "You go NORTH.\n\n";
		return nextRoom[0];

	default:
		return NULL;
	}
}

/*********************************************************************
*							 getHasBrick
*********************************************************************/
bool Room3::getHasBrick()
{
	return hasBrick;
}

/*********************************************************************
*							 setHasBrick
*********************************************************************/
void Room3::setHasBrick(bool x)
{
	hasBrick = x;
}