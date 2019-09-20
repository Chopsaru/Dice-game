/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Parent Die class. Inherrited by loadedDie.
*********************************************************************/

#include "Die.hpp"
#include <iostream>
#include <cstdlib>

/*********************************************************************
** Description: constructor, sets die sides
*********************************************************************/
Die::Die(int n) {
	nSides = n;
}

/*********************************************************************
** Description: creates a random seed for the rand method to generate a 
				random value between 1 and nSides
*********************************************************************/
int Die::roll() {
	int result = (rand() % nSides) + 1;
	return result;
}  
