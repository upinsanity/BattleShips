#pragma once
#include "Player.h"

#define INPUTFILE "./input.txt"
class BattleShipGame
{
	vector<Player> mPlayers;
public:		
	void start();
private:
	bool loadGame();
	int getOpposPlayer(int playerIdx);
};
