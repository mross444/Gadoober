/*********************************************************************
** File name: main.cpp
** Author:  Michael Ross
** Date: 3/22/17
** Description: main executable, contains the main menu and then calls
		the Game functions.
*********************************************************************/
#include "Game.hpp"

int main()
{
	bool validResponse;
	std::string userResponse;
	int menuOption = 0;

	// start main menu
	while (menuOption != 2)
	{
		menuOption = 0;
		validResponse = false;

		cout << "----- MIKE'S TEXT-BASED ADVENTURE GAME -----\n";
		cout << "1 - Start the game\n";
		cout << "2 - Exit\n";

		cout << "Please enter menu option: ";

		while (!validResponse)
		{
			getline(std::cin, userResponse);

			if (checkInputValue(userResponse, menuOption))
			{
				if (menuOption != 1 && menuOption != 2)
				{
					cout << "Invalid Response - Please enter a valid menu option: ";
				}
			}
			else
			{
				cout << "Please enter a valid menu option: ";
			}

			if (menuOption == 1 || menuOption == 2)
			{
				validResponse = true;
			}

			// play game
			if (menuOption == 1)
			{
				Game* dungeonManGame = new Game();
				dungeonManGame->playGame();
				delete dungeonManGame;
			}

		}

	}
	//end main menu

	return 0;
}