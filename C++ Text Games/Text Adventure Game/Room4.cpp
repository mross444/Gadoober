/*********************************************************************
** File name:  Room4.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#include "Room4.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Room4::Room4()
{
	withDennis = false;

	nextRoom[0] = NULL;
	nextRoom[1] = NULL;
	nextRoom[2] = NULL;
	nextRoom[3] = NULL;

	// Set script
	roomScript[0].text = "--------------------------------------------------\n";
	roomScript[0].text += "Ye arrive at the reception desk.  To the SOUTH(1) is \n";
	roomScript[0].text += "the FRONT DOOR.  There is DUNGEON CLERK(2) sitting at \n";
	roomScript[0].text += "a desk, though based on his loud snoring, he appears to \n";
	roomScript[0].text += "be asleep.  In the corner of the room is a COAT RACK";
	roomScript[1].text += "\ncontaining a DUSTY WOOL COAT(3)";
	roomScript[1].text += ". To the NORTH(4) is \nthe guard room.\n\n";
	roomScript[1].text += "What wouldst thou deau?\n";
	roomScript[2].text += "--------------------------------------------------\n\n";
	roomScript[2].text += "Enter Option: ";

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
			roomMenuChoice[i].interactionType = 2;
			roomMenuChoice[i].delFlg = 0;
		}

		else
		{
			roomMenuChoice[i].interactionType = 0;
			roomMenuChoice[i].delFlg = 1;
		}
	}

	roomOptions = 4;

	roomItem[3].setItemName("DUSTY OLD COAT");
	roomItem[3].setDelFlg(0);
}

/*********************************************************************
*						  selectRoomOption
*********************************************************************/
Room* Room4::selectRoomOption(int x)
{
	std::string s;

	switch (x)
	{
	case 1:
		if (!withDennis)
		{
			cout << "The DUNGEON CLERK wakes up!  \"Wait!\" he says! \n"
				<< "You can't go out there!  You have to give me the \n"
				<< "password!\n";

			getline(std::cin, s);

			cout << "\"WRONG!\" bellows the dusty clerk. \"Come back \n" 
				<< "when you have the password!\"\n\n";

			return NULL;
		}
		else
		{
			cout << "The DUNGEON CLERK wakes up!  \"Wait!\" he says! \n"
				<< "You can't... \" but it's too late! DENNIS has \n"
				<< "already paced all the way across the room and has \n"
				<< "paced right through the FRONT DOOR! You follow him \n"
				<< "out to what is surely freedom...\n\n";
			return nextRoom[2];
		}

	case 2:
		cout << "You approach the DUNGEON CLERK. He has a large bubble \n"
			<< "forming from his nose has he snores. You try to pop the \n"
			<< "bubble, but it does not pop.  Unfortunate.\n\n";

		return NULL;

	case 3:
		roomMenuChoice[2].delFlg = 1;
		roomScript[1].text.clear();
		roomScript[1].text += ".\nTo the NORTH(4) is the guard room.";
		roomScript[1].text += " What wouldst thou \ndeau?\n";

		return NULL;

	case 4:
		cout << "You go NORTH.\n\n";
		return nextRoom[0];

	default:
		return NULL;
	}
}

/*********************************************************************
*						   getWithDennis
*********************************************************************/
bool Room4::getWithDennis()
{
	return withDennis;
}

/*********************************************************************
*						   setWithDennis
*********************************************************************/
void Room4::setWithDennis(bool x)
{
	withDennis = x;
}