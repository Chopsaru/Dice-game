/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Child die class, inherrits from Die class
*********************************************************************/

#include "loadedDie.hpp"
#include <cstdlib>

loadedDie::loadedDie(int nSides) : Die(nSides) {}; // inherited constructor

/*********************************************************************
** Description: creates a random seed for the rand method to generate a
				random value between 2 and nSides thereby removing the
				lowest result and increasing the average roll.
*********************************************************************/
int loadedDie::roll() {
	int result = (rand() % nSides) + 2;
	return result;
} 
