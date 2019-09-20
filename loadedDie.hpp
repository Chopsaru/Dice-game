/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: header file for loadedDie
*********************************************************************/

#include "Die.hpp"

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class loadedDie : public Die {

	public:
		loadedDie(int nsides);

		int roll();
};

#endif 
