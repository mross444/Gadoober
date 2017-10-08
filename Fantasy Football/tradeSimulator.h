#ifndef TRADE_SIMULATOR_H
#define TRADE_SIMULATOR_H

#define PLAYER_NAME_SIZE 255
#define POS_NAME_SIZE 5
#define TEAM_PLAYER_SIZE 25
#define MAX_TEAMS 20
#define MAX_TRADES 1000
#define MAX_PLAYERS 1000
#define TEAM_NAME_SIZE 100

struct Player {
	int playerID;
	char playerPosition[POS_NAME_SIZE];
	char playerName[PLAYER_NAME_SIZE];
};

struct Team {
	int teamID;
	char teamName[TEAM_NAME_SIZE];
	int teamPlayers[TEAM_PLAYER_SIZE];
	int teamNumPlayers;
};

struct Trade {
	int tradePlayer1;
	int tradePlayer2;
	int tradeTeam1Improvement;
	int tradeTeam2Improvement;
};

struct Simulator {
	struct Player * simulatorPlayers[MAX_PLAYERS];
	struct Team * simulatorTeams[MAX_TEAMS];
	struct Trade * simulatorTrades[MAX_TRADES];
	int numTeams;
	int numPlayers;
	int numTrades;
};

// Player functions
void initPlayer(struct Player *, int, char *, char *);
struct Player * createPlayer(int, char *, char*);
int getPlayerRank(struct Player *);
char * getPlayerName(struct Player *);
char * getPlayerPosition(struct Player *);
void deletePlayer(struct Player *);

// Team functions
void initTeam(struct Team *, int, char *);
struct Team * createTeam(int, char *);
char * getTeamName(struct Team *);
int getTeamNumPlayers(struct Team *);
void increaseTeamCount(struct Team *);
void addPlayerToTeam(struct Team *, int);
int getPlayerFromTeam(struct Team *, int);
int calcFirstTeamScore(struct Team *);
void deleteTeam(struct Team *);

// Trade functions


// Simulator functions
void initSim(struct Simulator *);
struct Simulator * createSim();

void simAddPlayer(struct Simulator *, int, char *, char *, int);
int simCalcFirstTeamScore(struct Simulator *, struct Team *);
void deleteSim(struct Simulator *);

#endif