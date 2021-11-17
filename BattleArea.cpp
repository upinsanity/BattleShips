#include "BattleArea.h"

BattleArea::BattleArea(int nRows, int nCols) : m_nRowCount(nRows), m_nColCount(nCols), m_nShipCount(0) 
{
	m_Area.resize(nRows);
	for (int i = 0; i < nRows; i++)
		m_Area[i].resize(nCols, 0);
}

void BattleArea::addShip(int Type, int posX, int posY, int nHeight, int nWidth)
{
	for (int i = posX; i < posX + nWidth; i++)
	{
		for (int j = posY; j < posY + nHeight; j++)
		{
			m_Area[i][j] = Type;
			m_nShipCount+=Type;
		}
	}		
	
}

bool BattleArea::firedAt(int posX, int posY, bool &areAllShipsDestroyed)
{
	if (m_Area[posX][posY] != 0)
	{
		m_Area[posX][posY]--;
		m_nShipCount--;

		if (m_nShipCount == 0)
			areAllShipsDestroyed = true;
		return true;
	}
	return false;
}

void BattleArea::print()
{
	for (int i = 0; i < m_nRowCount; i++)
	{
		for (int j = 0; j < m_nColCount; j++)
			cout << m_Area[i][j] << "\t";
		cout << endl;
	}
}