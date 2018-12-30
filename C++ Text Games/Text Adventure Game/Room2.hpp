/*********************************************************************
** File name:  Room2.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#ifndef ROOM2_HPP
#define ROOM2_HPP

#include "Room.hpp"

class Room2 : public Room
{
private:
	bool hasWoolCoat;
	bool getHasWoolCoat();
	void setHasWoolCoat(bool);

public:
	Room2();
	Room* selectRoomOption(int);
	void updateRoom2();
};

#endif