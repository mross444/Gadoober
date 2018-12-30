/*********************************************************************
** File name: Game.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: class containing the logic that drives the game
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "DungeonMan.hpp"
#include "Room.hpp"
#include "Room1.hpp"
#include "Room2.hpp"
#include "Room3.hpp"
#include "Room4.hpp"
#include "Room5.hpp"
#include "Dennis.hpp"
#include "checkInputValue.hpp"

class Game
{
private:
	int gameTurns;
	bool gameWon;
	DungeonMan* thyDungeonMan;

public:
	Game();
	bool gameActive;
	void mainMenu();
	void playGame();
	int getGameTurns();
	bool getGameWon();
	void decreaseTurns();
	void setGameWon(bool);
	void setRoomFlags();
	Room* roomInteraction();
	Room* room1;
	Room* room2;
	Room* room3;
	Room* room4;
	Room* room5;
	Room* dennis;
	~Game();

};

#endif