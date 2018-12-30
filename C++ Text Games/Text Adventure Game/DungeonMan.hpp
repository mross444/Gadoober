/*********************************************************************
** File name: DungeonMan.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Class defining the player-controlled character used
	in the game.
*********************************************************************/
#ifndef DUNGEONMAN_HPP
#define DUNGEONMAN_HPP

#include "Item.hpp"
#include "Room.hpp"

class DungeonMan
{
private:
	Item backpack[10];
	int numItems;
	Room* occupiedRoom;
	Room* nextRoom;

public:
	DungeonMan();
	int getNumItems();
	void increaseItems();
	void decreaseItems();
	Room* getOccupiedRoom();
	void setOccupiedRoom(Room*);
	Room* getNextRoom();
	void setNextRoom(Room*);
	void getItemFromRoom(Room*, int);
};

#endif