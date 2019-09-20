/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: defines all class methods and compilers for Game object
*********************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Die.hpp"
#include "loadedDie.hpp"
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Description: Default constructor, sets wins to both player to 0
*********************************************************************/
Game::Game() {
	p1wins = 0;
	p2wins = 0;
}

/*********************************************************************
** Description: Main menu for diceGame. Asks users to play game (calls get data method)
				or exit game; validates input
*********************************************************************/
void Game::mainMenu() {
	int mmChoice;

	cout << endl << "Main Menu" << endl;									//main menu prompt
	cout << "=========" << endl << endl;
	cout << "Please select one of the following" << endl << endl;

	cout << "1. Play game" << endl;											//menu options
	cout << "2. Exit game" << endl << endl;

	do {
		menuError = false;
		cin >> mmChoice;
		if (cin.fail() || ((mmChoice != 1) && (mmChoice != 2))) {			//option validation
			menuError = true;
			cout << "Input error. Enter one of the menu numbers." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (menuError == true);

	switch (mmChoice) {
	case 1:																	//menu switch
		getData();
		break;
	case 2:
		exit(0);
		break;
	}
}

/*********************************************************************
** Description: prompts user for all game relevant data. then calls 
				the gameStart method.
*********************************************************************/
void Game::getData() {
	srand(time(0));

	cout << endl << "How many rounds will be played?" << endl;				//getnRounds
	do {
		menuError = false;
		cin >> nRounds;	
		if (cin.fail() || (nRounds < 0)) {									//option validation
			menuError = true;
			cout << "Input error. Enter a valid integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		} while (menuError == true);

	cout << "Will player one have loaded die? y/n" << endl;					//get p1Loaded
	do {
		menuError = false;
		cin >> p1Loaded;
		if (cin.fail() || ((p1Loaded != 'y') && (p1Loaded != 'n'))) {		//option validation
			menuError = true;
			cout << "Input error. Enter y for yes or n for no." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		} while (menuError == true);

		cout << "Will player two have loaded die? y/n" << endl;				//get p2Loaded
		do {
			menuError = false;
			cin >> p2Loaded;
			if (cin.fail() || ((p2Loaded != 'y') && (p2Loaded != 'n'))) {	//option validation
				menuError = true;
				cout << "Input error. Enter y for yes or n for no." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			} while (menuError == true);

		cout << "How many sides for player 1's die?" << endl;				//get p1's nsides
		do {
			p1sides = false;
			cin >> p1sides;
			if (cin.fail() || (p1sides < 2)) {								//1 sided die is impossible, 2 sided die is a coin, not a die
				menuError = true;
				cout << "Input error. Enter a valid intege above 2." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			} while (menuError == true);

		cout << "How many sides for player 2's die?" << endl;				//get p2's nsides
		do {
			p2sides = false;
			cin >> p2sides;
			if (cin.fail() || (p2sides < 2)) {								//1 sided die is impossible, 2 sided die is a coin, not a die
				menuError = true;
				cout << "Input error. Enter a valid integer above 2" << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		} while (menuError == true);
		
		gameStart();
}

/*********************************************************************
** Description: First creates relevant die classes for each player then
				begins the game using user data
*********************************************************************/
void Game::gameStart() {

	if (p1Loaded == 'y') {													//checking p1 loaded value, initializing class in context
		player1 = new loadedDie(p1sides);
	}
	else if (p1Loaded == 'n') {
		player1 = new Die(p1sides);
	}

	if (p2Loaded == 'y') {													//checking p2 loaded value, initializing class in context
		player2 = new loadedDie(p2sides);
	}
	else if (p2Loaded == 'n') {
		player2 = new Die(p2sides);
	}

	for (int i = 1; i < (nRounds + 1); i++) {								//nRounds loop
		p1result = player1->roll();
		p2result = player2->roll();

		cout << "Round: " << i << endl;										//printing round n results
		cout << "Player 1 rolled a " << p1result << " on a " << p1sides << " sided " << isP1Loaded() << " die." << endl;
		cout << "Player 2 rolled a " << p2result << " on a " << p2sides << " sided " << isP2Loaded() << " die." << endl;

		if (p1result < p2result) {
			//criticalThreat();
			cout << "Player 2 wins the round!" << endl << endl;
			p2wins++;
		}
		else if (p1result > p2result) {
			//criticalThreat();
			cout << "Player 1 wins the round!" << endl << endl;
			p1wins++;
		}
		else {
			//criticalThreat();
			cout << "This round is a tie!" << endl << endl;
			
		}
	}

	cout << endl << endl << "Final score:" << endl;							//print final results
	cout << "Player 1: " << p1wins << " wins" << "     " << "Player 2: " << p2wins << " wins" << endl;
	if (p1wins > p2wins) {
		cout << "Player 1 is victorious!" << endl;
	}
	else if (p1wins < p2wins) {
		cout << "Player 2 is victorious!" << endl;
	}
	else {
		cout << "Its a tie!" << endl;
	}

}

/*********************************************************************
** Description: checks if p1 has loaded die and returns the string "loaded"
				else return regular. Used for printing round results
*********************************************************************/
string Game::isP1Loaded() {
	if (p1Loaded == 'y'){
		return "loaded";
	}
	else {
		return "regular";
	}
}

/*********************************************************************
** Description: checks if p2 has loaded die and returns the string "loaded"
				else return regular. Used for printing round results
*********************************************************************/
string Game::isP2Loaded() {
	if (p2Loaded == 'y'){
		return "loaded";
	}
	else {
		return "regular";
	}
}

/*********************************************************************
** Description: For the programmers entertainment, can be ignored.
*********************************************************************/
/*
void Game::criticalThreat() {
	if (((p1result == 20) || (p2result == 20)) && ((p1sides == 20) || (p2sides == 20))) {
		cout << "Nat 20! Critical Threat!" << endl;
	}
}
*/

/*********************************************************************
** Description: destructor, deletes all die classes.
*********************************************************************/
Game::~Game() {
	delete player1;
	delete player2;
} 
