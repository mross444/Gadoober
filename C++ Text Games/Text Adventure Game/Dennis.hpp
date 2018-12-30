/*********************************************************************
** File name: Dennis.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: derived from Room class
*********************************************************************/

#ifndef DENNIS_HPP
#define DENNIS_HPP

#include "Room.hpp"

class Dennis : public Room
{
private:
	bool isOnFire;

public:
	Dennis();
	Room* selectRoomOption(int);
	bool getIsOnFire();
	void setIsOnFire(bool);
	void updateDennis();
};

#endif