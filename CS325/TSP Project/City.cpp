#include "City.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
City::City(int a, int b, int c) {
	id = a;
	x = b;
	y = c;
}

/*********************************************************************
*							   getID
*********************************************************************/
int City::getID()
{
	return id;
}

/*********************************************************************
*							    getX
*********************************************************************/
int City::getX()
{
	return x;
}

/*********************************************************************
*							    getY
*********************************************************************/
int City::getY()
{
	return y;
}
