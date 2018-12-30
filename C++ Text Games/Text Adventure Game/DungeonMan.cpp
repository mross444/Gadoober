/*********************************************************************
** File name: DungeonMan.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Class defining the player-controlled character used
		in the game.
*********************************************************************/

#include "DungeonMan.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
DungeonMan::DungeonMan()
{
	numItems = 0;
	occupiedRoom = NULL;
	nextRoom = NULL;

	for (int i = 0; i < 10; i++)
	{
		backpack[i].setDelFlg(1);
		backpack[i].setItemName("");
	}
}

/*********************************************************************
*							 getNumItems
*********************************************************************/
int DungeonMan::getNumItems()
{
	return numItems;
}

/*********************************************************************
*							 decreaseItems
*********************************************************************/
void DungeonMan::decreaseItems()
{
	numItems--;
}


/*********************************************************************
*							 increaseItems
*********************************************************************/
void DungeonMan::increaseItems()
{
	numItems++;
}

/*********************************************************************
*						    getOccupiedRoom
*********************************************************************/
Room* DungeonMan::getOccupiedRoom()
{
	return occupiedRoom;
}

/*********************************************************************
*						    setOccupiedRoom
*********************************************************************/
void DungeonMan::setOccupiedRoom(Room* r)
{
	occupiedRoom = r;
}

/*********************************************************************
*						     getNextRoom
*********************************************************************/
Room* DungeonMan::getNextRoom()
{
	return nextRoom;
}

/*********************************************************************
*						     setNextRoom
*********************************************************************/
void DungeonMan::setNextRoom(Room* r)
{
	nextRoom = r;
}

/*********************************************************************
*						    getItemFromRoom
*********************************************************************/
void DungeonMan::getItemFromRoom(Room* r, int x)
{		
	std::string s = r->getRoomItem(x);

	if (s != "")
	{
		backpack[numItems].setItemName(s);
		backpack[numItems].setDelFlg(0);
	}

	cout << "\n" << s << " added to your "
		<< "inventory.\n\n";

	numItems++;
}