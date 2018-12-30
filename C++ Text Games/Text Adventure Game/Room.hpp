/*********************************************************************
** File name: Room.hpp
** Author:  Michael Ross
** Date:  3/22/17
** Description: Abstract class for game spaces
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP

#include "Item.hpp"

#include <iostream>
#include <string>

using std::cout;

struct scriptPart
{
	std::string text;
	bool delFlg;
};

struct roomMenuOption
{
	int interactionType;
	bool delFlg;
};

class Room
{
protected:
	Room* nextRoom[4];
	scriptPart roomScript[10];
	int roomOptions;
	roomMenuOption roomMenuChoice[10];
	Item roomItem[5];

public:
	Room();
	void setNextRooms(Room*, Room*, Room*, Room*);
	Room* getNextRoom(int);
	std::string getRoomScript();
	int getRoomOptions();
	int getRoomOptionInteractionType(int);
	bool getRoomOptionInteractionDelFlg(int);
	void decreaseRoomOptions();
	virtual Room* selectRoomOption(int);

	virtual bool getHasBrick();
	virtual void setHasBrick(bool);

	virtual bool getWithDennis();
	virtual void setWithDennis(bool); 

	virtual bool getHasWoolCoat();
	virtual void setHasWoolCoat(bool);
	virtual void updateRoom2();

	virtual bool getIsOnFire();
	virtual void setIsOnFire(bool);
	virtual void updateDennis();

	std::string getRoomItem(int);

};



#endif