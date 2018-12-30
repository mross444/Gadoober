/*********************************************************************
** File name:  Room1.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#ifndef ROOM1_HPP
#define ROOM1_HPP

#include "Room.hpp"

class Room1 : public Room
{
public:
	Room1();
	Room* selectRoomOption(int);
};

#endif