/*********************************************************************
** File name:  Room5.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#ifndef ROOM5_HPP
#define ROOM5_HPP

#include "Room.hpp"

class Room5 : public Room
{
public:
	Room5();
	Room* selectRoomOption(int);
};

#endif