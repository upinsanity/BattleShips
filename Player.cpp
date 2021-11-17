#include "Player.h"
Player::Player(int nRow, int nCol)
{
	m_BattleArea = new BattleArea(nRow, nCol);
}
Player::~Player()
{
	if(m_BattleArea)
		delete m_BattleArea;
}
void Player::placeShip(int nHeight, int nWidth, int posX, int posY, eShipType type)
{
	m_BattleArea->addShip(type, posX, posY, nHeight, nWidth);
}

bool Player::firedAt(int posX, int posY, bool &bAllShipsShot)
{
	return m_BattleArea->firedAt(posX, posY, bAllShipsShot);
}

void Player::printBattleArea()
{
	m_BattleArea->print();
}

string Player::getNextMove()
{
	string move = "";
	if (!m_Moves.empty())
	{
		move = m_Moves.front();
		m_Moves.pop();
	}
	return move;
}
