#ifndef TRADE_SIMULATOR_H
#define TRADE_SIMULATOR_H

#define PLAYER_NAME_SIZE 255
#define POS_NAME_SIZE 5
#define TEAM_PLAYER_SIZE 25

struct Player {
	int playerID;
	char playerPosition[POS_NAME_SIZE];
	char playerName[PLAYER_NAME_SIZE];
};

struct Team {
	int teamID;
	struct Player * teamPlayers[TEAM_PLAYER_SIZE];
	int teamNumPlayers;
};

struct Trade {
	int tradeTeam1;
	int tradeTeam2;
	struct Player * tradePlayer1;
	struct Player * tradePlayer2;
	int tradeTeam1Improvement;
	int tradeTeam2Improvement;
	int tradeToalImpovement;
};

struct Simulator {
	struct Team ** simulatorTeams;
	struct Trade ** simulatorTrades;
	int numTeams;
};


void initPlayer(struct Player *, int, char*, char*);
struct Player * createPlayer(int, char*, char*);
int getPlayerRank(struct Player *);
char * getPlayerName(struct Player *);
char * getPlayerPosition(struct Player *);
void deletePlayer(struct Player *);

void initTeam(struct Team *, int);
struct Team * createTeam(int);
int getTeamNumPlayers(struct Team *);
void increaseTeamCount(struct Team *);
void addPlayerToTeam(struct Player *, struct Team *);
struct Player * getPlayerFromTeam(struct Team *, int);
int calcFirstTeamScore(struct Team *);
void deleteTeam(struct Team *);




#endif