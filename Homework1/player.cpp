//Matthew O'brien
//Jan 30th
//Assignment 1




//File for the prototypes for the players of the game
//Again some of these functions won't work and will be
//commented out for later use in the gameplay itself.

#include "player.h"

//Constructor
hand::hand()
{
	for(int i = 0; i<10;++i)
	{
		player_hand[i] = NULL;
	}
}


//Destructor
hand::~hand()
{
	for(int i=0;i<10;++i)
	{
		delete player_hand[i];
		player_hand[i] = NULL;
	}
}



/*Creates a hand. This function was a bad idea. Keeping it just in case.
void hand::create_hand()
{
	for(int i = 0; i < 10; ++i)
	{
		player_hand[i] = new bone;
	}
}*/



//Draws a single bone and adds to the player hand to an empty position in the array
void hand::draw_bone(bone & to_copy)
{

	int i = 0;
	do
	{
		if(!player_hand[i])
		{
			player_hand[i] = new bone;
			player_hand[i]->copy_bone(to_copy);
			return;
		}
		else
			++i;
	}while( i < 10);		
	
}


//Displays the player's hand. Skipping the array positions with pointers to NULL
void player::display_hand()
{
	int i = 0;
	for(int i = 0; i < 10; ++i)
	{
		if(player_hand[i])
			player_hand[i]->display();
	}

	cout<<endl;
}
	
			

//Shows the player's "score" of all the bones added up
void player::display_score()
{

	int i = 0;
	
	for(int j = 0; j < 10; ++j)
	{
		if(player_hand[j])
			i = i + player_hand[j]->get_value1() + player_hand[j]->get_value2();
	}	

	score = i;
	cout<<"Player score:"<<score<<endl<<endl;
}
