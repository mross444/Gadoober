/*********************************************************************
** File name:  Room4.hpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: Derived from Room class
*********************************************************************/

#ifndef ROOM4_HPP
#define ROOM4_HPP

#include "Room.hpp"

class Room4 : public Room
{
private:
	bool withDennis;
public:
	Room4();
	Room* selectRoomOption(int);
	bool getWithDennis();
	void setWithDennis(bool);
};

#endif