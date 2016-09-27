//Matthew O'Brien
//Assignment 2





//This file will contain the prototypes for the field class. The design of 
//this class is to handle the bones being played onto the gameboard.
//It will show the availables bones to be played off of until it reaches a 
//chicken foot. At which point that position will not longer be available for
//play. 



#include "player.h"


class field
{

	public:
		field();
		~field();
		void display_ends();
		void add_bone(int position, bone& to_copy);
		
	protected:
		//Static allocation. Never want more then these pointers
		bone * field_array[5];
};
