#include "tradeSimulator.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void initPlayer(struct Player * pl, int id, char * pos, char * nm) {
	pl->playerID = id;
	strcpy(pl->playerPosition, pos);
	strcpy(pl->playerName, nm);
}

struct Player * createPlayer(int id, char * pos, char * nm) {
	struct Player * newPlayer = malloc(sizeof(struct Player));
	initPlayer(newPlayer, id, pos, nm);
	return newPlayer;
}

int getPlayerRank(struct Player * pl) {
	return pl->playerID;
}

char * getPlayerName(struct Player * pl) {
	return pl->playerName;
}

char * getPlayerPosition(struct Player * pl) {
	return pl->playerPosition;
}

void deletePlayer(struct Player * pl) {
	free(pl);
}


void initTeam(struct Team * team, int id) {
	team->teamID = id;
	team->teamNumPlayers = 0;
}

struct Team * createTeam(int id) {
	struct Team * newTeam = malloc(sizeof(struct Team));
	initTeam(newTeam, id);
	return newTeam;
}

int getTeamNumPlayers(struct Team * tm) {
	return tm->teamNumPlayers;
}

void increaseTeamCount(struct Team * tm) {
	tm->teamNumPlayers++;
}

void addPlayerToTeam(struct Player * pl, struct Team * tm) {
	tm->teamPlayers[getTeamNumPlayers(tm)] = pl;
	increaseTeamCount(tm);
}

struct Player * getPlayerFromTeam(struct Team * tm, int idx) {
	return tm->teamPlayers[idx];
}

int calcFirstTeamScore(struct Team * tm) {

	int numQBs = 0;
	int numRBs = 0;
	int numWRs = 0;
	int numTEs = 0;
	int numDST = 0;
	int numK = 0;
	int teamScore = 0;

	printf("Calculating First Team Score:\n\n");

	int i = 0;
	while (numQBs < 1 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "QB") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numQBs++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	i = 0;
	while (numRBs < 2 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "RB") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numRBs++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	i = 0;
	while (numWRs < 2 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "WR") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numWRs++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	i = 0;
	while (numTEs < 1 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "TE") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numTEs++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	i = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	while (numRBs <= 2 && numWRs <= 2 && numTEs <= 2 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "RB") == 0) {
			
			if (x == 2) {
				printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
				printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
				printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
				numRBs++;
				teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
			}
			else {
				x++;
			}

		}

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "WR") == 0) {

			if (y == 2) {
				printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
				printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
				printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
				numWRs++;
				teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
			}
			else {
				y++;
			}

		}

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "TE") == 0) {

			if (z == 1) {
				printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
				printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
				printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
				numTEs++;
				teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
			}
			else {
				z++;
			}

		}

		i++;

	}


	i = 0;
	while (numDST < 1 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "DST") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numDST++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	i = 0;
	while (numK < 1 && i < tm->teamNumPlayers) {

		if (strcmp(getPlayerPosition(getPlayerFromTeam(tm, i)), "K") == 0) {
			printf("%d, ", getPlayerRank(getPlayerFromTeam(tm, i)));
			printf("%s, ", getPlayerPosition(getPlayerFromTeam(tm, i)));
			printf("%s\n", getPlayerName(getPlayerFromTeam(tm, i)));
			numK++;
			teamScore += getPlayerRank(getPlayerFromTeam(tm, i));
		}

		i++;
	}

	if (numQBs != 1) {
		teamScore += 200;
	}

	if (numRBs <= 2) {
		teamScore += (2 - numRBs) * 200;
	}

	if (numWRs <= 2) {
		teamScore += (2 - numWRs) * 200;
	}

	if (numTEs != 1) {
		teamScore += 200;
	}

	if (numDST != 1) {
		teamScore += 200;
	}

	if (numK != 1) {
		teamScore += 300;
	}

	return teamScore;

}

void deleteTeam(struct Team * tm) {
	free(tm);
}