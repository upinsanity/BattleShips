// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include <fstream>
#include <string>
#include "BattleShipGame.h"
using namespace std;

bool BattleShipGame::loadGame()
{
	cout << "Loading configuration...\n";
	std::ifstream ifs;
	ifs.open(INPUTFILE, std::ifstream::in);
	if (ifs.good())
	{
		int col;
		char rowCh;
		ifs >> col;
		ifs >> rowCh;
		int row = rowCh - 'A' + 1;
		mPlayers.push_back(Player(row, col));
		mPlayers.push_back(Player(row, col));

		int shipCount;
		ifs >> shipCount;

		while (shipCount--)
		{
			char shipType;
			ifs >> shipType;

			int nHeight, nWidth;
			ifs >> nHeight >> nWidth;

			for (auto p : mPlayers)
			{
				char rowPosCh;
				ifs >> rowPosCh;
				int rowPos = rowPosCh - 'A';

				int colPos;
				ifs >> colPos;

				eShipType T = (shipType == 'Q') ? eShipType::Q : eShipType::P;
				p.placeShip(nHeight, nWidth, rowPos, colPos - 1, T);
			}
		}

		int playerIdx = 0;
		while (ifs.good())
		{
			char line[1024] = { '\0' };
			ifs.getline(line, 1024);

			string str(line);
			if (!str.empty())
			{
				Player& p = mPlayers[playerIdx++];

				char* token = strtok(line, " ");
				while (token)
				{
					p.addMove(string(token));
					token = strtok(NULL, " ");
				}
			}
		}
		ifs.close();
		return true;
	}
	return false;
}

int BattleShipGame::getOpposPlayer(int playerIdx)
{
	if (playerIdx == 0)
		return 1;
	return 0;
}

void BattleShipGame::start()
{
	if (!loadGame())
		return;

	cout << "Player battle fields at begining - \n";
	for (auto p : mPlayers)
	{
		p.printBattleArea();
		cout << endl << endl;
	}

	cout << "Staring game- \n";
	int playerIdx = 0;
	while (1)
	{
		cout << "Player" << playerIdx + 1 << ":\n";

		int getOpposingPlayerIdx = getOpposPlayer(playerIdx);
		string missle = mPlayers[playerIdx].getNextMove();
		if (missle.empty())
			cout << "No more missles to launch\n";
		else
		{
			cout << "Loading missle at - ";
			cout << missle << endl;
			int posX = missle[0] - 'A';
			int posY = missle[1] - '0' - 1;

			bool areAllShipsDown = false;
			while (mPlayers[getOpposingPlayerIdx].firedAt(posX, posY, areAllShipsDown))
			{
				cout << "HIT!!\n";
				if (areAllShipsDown)
				{
					cout << "Game Over.  Player " << playerIdx + 1 << " won!!\n";
					break;
				}
				cout << "Loading missle at - ";
				missle = mPlayers[playerIdx].getNextMove();
				cout << missle << endl;
				posX = missle[0] - 'A';
				posY = missle[1] - '0' - 1;
			}
			if (areAllShipsDown)
				break;

			cout << "MISS X\n";
		}
		playerIdx = getOpposingPlayerIdx;
	}

	cout << "Player battle fields at end - \n";
	for (auto p : mPlayers)
	{
		p.printBattleArea();
		cout << endl << endl;
	}
}




