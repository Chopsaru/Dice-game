/*********************************************************************
** Author: Greg Noetzel
** Date: 7/4/2019
** Description: Header file for Die.cpp
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die {
	protected:
		int nSides;

	public:
		Die(int nsides);

		virtual int roll();
};

#endif 
