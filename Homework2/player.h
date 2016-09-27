 //Matthew O'Brien
//Jan 30th
//Assignment 1




//This file contains the player and hand classes for the game. They will contain an array of a set size
//for the player. There will also be a display for the bones in the hand, and the current score of the player.
//The score portion will control when the game ends. Resetting the score of a player will be used often
//throughout the program to know when a player  has won.


#include "pile.h"




class hand
{

	public:
		hand();
		~hand();
//		void draw_bone(bone & to_copy); 
		void draw_hand();
		int biggest_double();
		int double_position();
		virtual void display_hand();		
	
	protected:
		//Handicap of no more then 10 tiles.
		bone * player_hand[10];
};


class player: public hand
{

	public:
		void draw_bone(bone & to_copy);
		void display_score();
		void display_hand();
		bone* play_bone(int num);
		void skip_turn();
		void delete_bone(int num);
		int get_score();
		void set_score();	
	protected:
		int score;//Controls the winner!
};
