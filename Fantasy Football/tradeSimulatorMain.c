#include "tradeSimulator.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main() {

	struct Player * myPlayer1 = createPlayer(2, "RB", "Le'veon Bell");
	struct Player * myPlayer2 = createPlayer(19, "WR", "Amari Cooper");
	struct Player * myPlayer3 = createPlayer(26, "RB", "Lamar Miller");
	struct Player * myPlayer4 = createPlayer(36, "TE", "Travis Kelce");
	struct Player * myPlayer5 = createPlayer(41, "RB", "Joe Mixon");
	struct Player * myPlayer6 = createPlayer(52, "WR", "Martavis Bryant");
	struct Player * myPlayer7 = createPlayer(81, "WR", "Devante Parker");
	struct Player * myPlayer8 = createPlayer(92, "WR", "Tyrell Williams");
	struct Player * myPlayer9 = createPlayer(94, "RB", "Derrick Henry");
	struct Player * myPlayer10 = createPlayer(107, "TE", "Hunter Henry");
	struct Player * myPlayer11 = createPlayer(113, "QB", "Andy Dalton");
	struct Player * myPlayer12 = createPlayer(126, "RB", "C.J. Prosise");
	struct Player * myPlayer13 = createPlayer(155, "WR", "Kevin White");
	struct Player * myPlayer14 = createPlayer(157, "DST", "Arizona Cardinals");
	struct Player * myPlayer15 = createPlayer(177, "WR", "Robert Woods");
	struct Player * myPlayer16 = createPlayer(252, "K", "Sebastian Janikowski");

	struct Team * myTeam = createTeam(1);
	addPlayerToTeam(myPlayer1, myTeam);
	addPlayerToTeam(myPlayer2, myTeam);
	addPlayerToTeam(myPlayer3, myTeam);
	addPlayerToTeam(myPlayer4, myTeam);
	addPlayerToTeam(myPlayer5, myTeam);
	addPlayerToTeam(myPlayer6, myTeam);
	addPlayerToTeam(myPlayer7, myTeam);
	addPlayerToTeam(myPlayer8, myTeam);
	addPlayerToTeam(myPlayer9, myTeam);
	addPlayerToTeam(myPlayer10, myTeam);
	addPlayerToTeam(myPlayer11, myTeam);
	addPlayerToTeam(myPlayer12, myTeam);
	addPlayerToTeam(myPlayer13, myTeam);
	addPlayerToTeam(myPlayer14, myTeam);
	addPlayerToTeam(myPlayer15, myTeam);
	addPlayerToTeam(myPlayer16, myTeam);


	printf("Total First Team Score: %d\n\n", calcFirstTeamScore(myTeam));

	deleteTeam(myTeam);

	deletePlayer(myPlayer1);
	deletePlayer(myPlayer2);
	deletePlayer(myPlayer3);
	deletePlayer(myPlayer4);
	deletePlayer(myPlayer5);
	deletePlayer(myPlayer6);
	deletePlayer(myPlayer7);
	deletePlayer(myPlayer8);
	deletePlayer(myPlayer9);
	deletePlayer(myPlayer10);
	deletePlayer(myPlayer11);
	deletePlayer(myPlayer12);
	deletePlayer(myPlayer13);
	deletePlayer(myPlayer14);
	deletePlayer(myPlayer15);
	deletePlayer(myPlayer16);


	printf("Done\n\n");

	return 0;

}