/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: header file for Game.cpp, initializes all variables and 
				methods and objects for the game to run under Game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include <string>

using std::string;

class Game {
	private:
		int nRounds;
		int p1wins;
		int p2wins;
		int p1sides;
		int p2sides;
		int roundCount;
		int p1result;
		int p2result;
		bool menuError;
		char p1Loaded;
		char p2Loaded;
		string isLoaded;

		Die* player1;
		Die* player2;

	public:
		Game();
		~Game();

		void mainMenu();
		void getData();
		void gameStart();
		string isP1Loaded();
		string isP2Loaded();
		//void criticalThreat();

};

#endif 