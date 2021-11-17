#pragma once
#include <vector>
#include <iostream>
using namespace std;

typedef enum
{
	P = 1,
	Q = 2
}eShipType;

class BattleArea
{
	vector<vector<int>> m_Area;
	int m_nRowCount;
	int m_nColCount;
	int m_nShipCount;

public:
	BattleArea(int nRows, int nCols); 
	void addShip(int Type, int posX, int posY, int nHeight, int nWidth);
	bool firedAt(int posX, int posY, bool& areAllShipsDestroyed);
	void print();
};