 //Matthew O'Brien
//Jan 30th
//Assignment 1




//This file will contain the information for my player class. Some of these functions
//will not actually do anything right now, as they will interact with the board game itself.
//For the time being they should only contain an array for the player hand. 


#include "pile.h"

//Some of these functions aren't implemented yet
//This is due to the game class having not been created
//so there is no way for them to interact with the
//needed classes.

//For example the draw_bone function is suppose to be
//called later on for draw_hand()
//But I don't have access to the pile until the game
//class is created

//Other functions were commented out, but left just
//in case they become useful later on.

class hand
{

	public:
		hand();
		~hand();
		void draw_bone(bone & to_copy);
//		void create_hand();		

		void draw_hand();	
	
	protected:
		//Handicap of no more then 10 tiles.
		bone * player_hand[10];
};


class player: public hand
{

	public:
		void display_score();
		void display_hand();
		void play_bone();//Not implemented yet
		void skip_turn();//Not implemented yet
	
	protected:
		int score;
};
