/*********************************************************************
** File name:  Room3.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#ifndef ROOM3_HPP
#define ROOM3_HPP

#include "Room.hpp"

class Room3 : public Room
{
private:
	bool hasBrick;
public:
	Room3();
	Room* selectRoomOption(int);
	bool getHasBrick();
	void setHasBrick(bool);
};

#endif