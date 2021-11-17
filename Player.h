#pragma once
#include "BattleArea.h"
#include<queue>
#include<string> 
class Player
{
	BattleArea* m_BattleArea;
	queue<string> m_Moves;
public:
	Player(int nRow, int nCol);
	void placeShip(int nHeight, int nWidth, int posX, int posY, eShipType type);
	bool firedAt(int posX, int posY, bool& bAllShipsShot);
	void printBattleArea();
	void addMove(string strNextMove) { m_Moves.push(strNextMove); }
	string getNextMove();
};