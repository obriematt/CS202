//Matthew O'Brien
//Assignment 2





//Contains the functions for the field class. This will be a 
//rather simple and short class. As it is only suppose to hold the bones
//that were played by a player and display the ends.



#include "field.h"

//Field constructor. Builds the board
field::field()
{
	//Setting each position of the array to NULL
	for(int i=0; i<5; ++i)
	{
		field_array[i] = NULL;
	}
}



//Field Destructor. Destroys the board.
field::~field()
{
	for(int i=0; i<5; ++i)
	{
		//Checking to make sure it's there
//		if(!field_array[i])
//		{
//			delete field_array[i];
//			field_array[i] = NULL;
//		}
		//Moving through the bones in the array of LLL and deleting them. Setting to NULL
		while(field_array[i])
		{
			bone * temp = field_array[i];
			field_array[i] = field_array[i] -> next_ptr();
			delete temp;
			temp = NULL;
		}
	}
}



//This function will copy a bone over to the given position
//in the field. If needed, will traverse to the end of the list and add there.
void field::add_bone(int position, bone& to_copy)
{
	int i = position;
	//Check to see if the initial position is pointing to anything, adding there if not.
	if(!field_array[i])
	{
		field_array[i] = new bone;
		field_array[i]->copy_bone(to_copy);
		return;
	}
	//Moving through the list to the end, and adding the new bone.
	else
	{
		bone * current = field_array[i];
		while(current->next_ptr())
		{
			current=current->next_ptr();
		}
		bone * temp = new bone;
		temp->copy_bone(to_copy);
		current->set_next(temp);
	}			
	
}


void field::display_ends()
{
	//Displays the first double played. Automically filled.
	if(field_array[0])
	{
		cout<<"The starting double for the round!"<<endl;
		field_array[0]->display();
		cout<<endl;
	}
	//Moves through the starting positions from array and displays the dominos that were added to it.
	for(int i=1; i<5;++i)
	{
		//These positions are the points from the starting double that the player can play from.
		//Empty position, available for play.
		if(!field_array[i])
			cout<<"The "<<i<<" position is available for play off the starting bone."<<endl;
		//Shows the bones from that position
		else
		{
			cout<<"The "<<i<<" position bones are. "<<endl;
			bone * current = field_array[i];
			current->display();
			while(current->next_ptr())
			{
				current = current->next_ptr();
				current->display();
			}		
		}	
	}
}

