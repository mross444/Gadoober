/*********************************************************************
** File name:  Room2.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#include "Room2.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Room2::Room2()
{
	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "--------------------------------------------------\n";
	roomScript[0].text += "Ye arrive at a CREEPY CORRIDOR. \n";
	roomScript[1].text += "On the wall is a TORCH(1) attached to a SCONE.\n";
	roomScript[2].text += "There's a DILAPIDATED LADDER(2) leading to what could \n";
	roomScript[2].text += "be another floor above head.\n";
	roomScript[3].text += "Back to the SOUTH(3) is your dungeon cell.";
	roomScript[3].text += "\n\nWhat wouldst thou deau?\n";
	roomScript[3].text += "--------------------------------------------------\n\n";
	roomScript[3].text += "Enter Option: ";

	for (int i = 0; i < 10; i++)
	{
		if (i < 4)
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

	roomOptions = 3;

	hasWoolCoat = false;
	roomItem[1].setItemName("ON FIRE");
	roomItem[1].setDelFlg(0);
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Room2::selectRoomOption(int x)
{
	switch (x)
	{
	case 1:
		if (hasWoolCoat)
		{
			cout << "You reach up for the TORCH, though your DUSTY \n"
				<< "WOOL COAT makes things difficult.  You end up \n"
				<< "snagging a long strand on the SCONE, which catches \n"
				<< "ablaze. Before you can get it off, the whole coat \n"
				<< "on fire. Oh No! Why did you even go for the TORCH - \n"
				<< "it was attached to the SCONE!\n\n";

			roomMenuChoice[0].delFlg = 1;
			roomScript[1].delFlg = 1;

			return NULL;
		}
		else
		{
			cout << "You attempt to take the torch, though it is just \n"
				<< "out of reach.  Maybe come back for it later...\n\n";

			return NULL;
		}

	case 2:
		cout << "You attempt to climb the DILAPIDATED LADDER, but alas, \n"
			<< "it is far too dilapated. It quickly crumbles into a mere \n"
			<< "rubble.\n\n";

		roomMenuChoice[1].delFlg = 1;
		roomScript[2].delFlg = 1;

		return NULL;

	case 3:
		cout << "You go SOUTH.\n\n";
		return nextRoom[2];

	default:
		return NULL;
	}
}

/*********************************************************************
*						   getWithDennis
*********************************************************************/
bool Room2::getHasWoolCoat()
{
	return hasWoolCoat;
}

/*********************************************************************
*						   setWithDennis
*********************************************************************/
void Room2::setHasWoolCoat(bool x)
{
	hasWoolCoat = x;
}

/*********************************************************************
*							 update Room2
*********************************************************************/
void Room2::updateRoom2()
{
	roomMenuChoice[0].interactionType = 2;
}