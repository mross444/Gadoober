/*********************************************************************
** File name: Game.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: class containing the logic that drives the game
*********************************************************************/
#include "Game.hpp"

/*********************************************************************
*							 constructor
*********************************************************************/
Game::Game()
{
	gameActive = false;
	gameTurns = 100;
	gameWon = false;

	room1 = new Room1();
	room2 = new Room2();
	room3 = new Room3();
	room4 = new Room4();
	room5 = new Room5();
	dennis = new Dennis();


	room1->setNextRooms(room2, dennis, room3, NULL);
	room2->setNextRooms(NULL, NULL, room1, NULL);
	room3->setNextRooms(room1, NULL, room4, NULL);
	room4->setNextRooms(room3, NULL, room5, NULL);
	room5->setNextRooms(NULL, NULL, NULL, NULL);
	dennis->setNextRooms(NULL, NULL, NULL, room1);

	thyDungeonMan = new DungeonMan();
	thyDungeonMan->setOccupiedRoom(room1);
}

/*********************************************************************
*							  mainMenu
*********************************************************************/
void Game::mainMenu()
{
	
}

/*********************************************************************
*							  playGame
*********************************************************************/
void Game::playGame()
{
	gameActive = false;
	gameTurns = 100;
	gameWon = false;
	thyDungeonMan->setOccupiedRoom(room1);

	bool x = false;
	Room* nextRoom = NULL;

	while (!x)
	{
		nextRoom = roomInteraction();

		if (nextRoom != NULL)
		{
			thyDungeonMan->setOccupiedRoom(nextRoom);
		}

		decreaseTurns();

		x = getGameWon();

		if (getGameTurns() == 0)
		{
			cout << "\n\nGame Over.\n\n";
			setGameWon(true);
		}

		if (x)
		{
			cout << "You Win!  Remaining turns: " << getGameTurns() << "\n\n\n";
		}

	}
}

/*********************************************************************
*						   roomInteraction
*********************************************************************/
Room* Game::roomInteraction()
{
	setRoomFlags();

	// Read the room's script
	cout << (thyDungeonMan->getOccupiedRoom())->getRoomScript();

	bool validResponse = false;
	std::string userResponse;
	int menuOption = 0;

	while (!validResponse)
	{
		getline(std::cin, userResponse);

		if (checkInputValue(userResponse, menuOption))
		{
			if (menuOption <= 0 || menuOption > thyDungeonMan->getOccupiedRoom()->getRoomOptions())
			{
				cout << "Invalid Response - Please enter a valid menu option: ";
			}
		}
		else
		{
			cout << "Please enter a valid menu option: ";
		}

		if (thyDungeonMan->getOccupiedRoom() == room5)
		{
			setGameWon(true);
		}

		if (menuOption > 0 && menuOption <= thyDungeonMan->getOccupiedRoom()->getRoomOptions() 
			&& thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionType(menuOption) == 1)
		{
			if (thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionDelFlg(menuOption) == 0)
			{
				validResponse = true;
				return thyDungeonMan->getOccupiedRoom()->selectRoomOption(menuOption);
			}

			else
			{
				cout << "Invalid Response - Please enter a valid menu option: ";
			}
		}

		if (menuOption > 0 && menuOption <= thyDungeonMan->getOccupiedRoom()->getRoomOptions()
			&& thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionType(menuOption) == 2)
		{
			if (thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionDelFlg(menuOption) == 0)
			{
				validResponse = true;
				thyDungeonMan->getItemFromRoom(thyDungeonMan->getOccupiedRoom(), menuOption);
				return thyDungeonMan->getOccupiedRoom()->selectRoomOption(menuOption);
			}

			else
			{
				cout << "Invalid Response - Please enter a valid menu option: ";
			}
		}

		if (menuOption > 0 && menuOption <= thyDungeonMan->getOccupiedRoom()->getRoomOptions()
			&& thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionType(menuOption) == 3)
		{
			if (thyDungeonMan->getOccupiedRoom()->getRoomOptionInteractionDelFlg(menuOption) == 0)
			{
				validResponse = true;
				return thyDungeonMan->getOccupiedRoom()->selectRoomOption(menuOption);
			}

			else
			{
				cout << "Invalid Response - Please enter a valid menu option: ";
			}
		}
	}



	return NULL;
}

/*********************************************************************
*						   setRoomFlags
*********************************************************************/
void Game::setRoomFlags()
{
	if (thyDungeonMan->getOccupiedRoom() == room3)
	{
		if (thyDungeonMan->getNumItems() > 0)
		{
			room3->setHasBrick(true);
		}

		else
		{
			room3->setHasBrick(false);
		}
	}

	if (thyDungeonMan->getOccupiedRoom() == room2)
	{
		if (thyDungeonMan->getNumItems() > 1)
		{
			room2->setHasWoolCoat(true);
			room2->updateRoom2();
		}

		else
		{
			room2->setHasWoolCoat(false);
		}
	}

	if (thyDungeonMan->getOccupiedRoom() == dennis)
	{
		if (thyDungeonMan->getNumItems() == 3)
		{
			dennis->updateDennis();
		}

		else
		{
			room2->setHasWoolCoat(false);
		}
	}

	if (thyDungeonMan->getOccupiedRoom() == room4)
	{
		if (thyDungeonMan->getNumItems() > 3)
		{
			room4->setWithDennis(true);
		}

		else
		{
			room4->setWithDennis(false);
		}
	}


}

int Game::getGameTurns()
{
	return gameTurns;
}

bool Game::getGameWon()
{
	return gameWon;
}

void Game::decreaseTurns()
{
	gameTurns--;
}

void Game::setGameWon(bool x)
{
	gameWon = x;
}

/*********************************************************************
*							 destructor
*********************************************************************/
Game::~Game()
{
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete dennis;
	delete thyDungeonMan;
}