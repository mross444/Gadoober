#ifndef CITY_HPP
#define CITY_HPP

class City {
protected:
	int id; //City ID
	int x; //x coordinate
	int y; //y coordinate

public:
	City(int, int, int);
	int getID();
	int getX();
	int getY();
};

#endif