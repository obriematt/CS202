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




//Virtual function to display the hand from the player class.
void hand::display_hand()
{

}


//Returns the player's score to check for victory
int player::get_score()
{
	return score;
}




//Gives the player a score for the bones they have in their hand. Called whenever the hand changes
void player::set_score()
{
	int i = 0;
	
	for(int j = 0; j < 10; ++j)
	{
		//Make sure the position has something in it.
		if(player_hand[j])
			i = i + player_hand[j]->get_value1() + player_hand[j]->get_value2();//Adds up the score of all the bones.
	}	
	//Sets score equal to it's new value
	score = i;
}


//Finds the biggest double in a player's hand, and returns it's position. 
//This function is used only for the initial automatic bone play.
int hand::double_position()
{
	int position = 0;
	int sum = 0;
	//Searching through the hand
	for(int i=0;i<10;++i)
	{
		//Making sure something is there
		if(player_hand[i])
		{
			//Checking to see if the bone is a double, and checking to see if the values of the bone are higher then previous doubles.
			if(player_hand[i]->double_check() && player_hand[i]->get_value1()>sum)
			{	
				sum = player_hand[i]->get_value1();
				position = i;
			}
		}
		
	}
	//Returning the position in the hand. Used for adding bones
	return position;	
}


//Finds the sum of the biggest double in a players hand. Used to check against other player hands.
int hand::biggest_double()
{	
	int sum = 0;
	//Looking through the player's hand
	for(int i=0;i<10;++i)
	{
		//Making sure that position is pointing to a bone
		if(player_hand[i])
 		{
			//Checking for doubles. Making sure that value is larger then the previous
			if(player_hand[i]->double_check() && player_hand[i]->get_value1() > sum)
				sum = player_hand[i]->get_value1();//Saving new largest
		}
	}
	//Returning the value of the largest
	return sum;
}  
			
				

//Deletes a bone from a player's hand
void player::delete_bone(int num)
{
	delete player_hand[num];
	player_hand[num] = NULL;
	set_score();
}	




//Plays a bone from a hand. Returns a bone pointer easily passed and copied elsewhere
bone * player::play_bone(int num)
{
	if(player_hand[num])
		return player_hand[num];
}
		


//Draws a single bone and adds to the player hand to an empty position in the array
void player::draw_bone(bone & to_copy)
{

	int i = 0;
	do
	{
		//Checking to see if the position of the hand is empty
		if(!player_hand[i])
		{
			//adds a bone at the empty position
			player_hand[i] = new bone;
			player_hand[i]->copy_bone(to_copy);
			return;
		}
		else
			++i;//Trying to find an empty spot.
	}while( i < 10);//If i passes 10, the hand is full. no more bones.
	set_score();//Hand might have been changed. Resetting score.		
	
}


//Displays the player's hand. Skipping the array positions with pointers to NULL
void player::display_hand()
{
	int i = 0;
	//Moves through the hand
	for(int i = 0; i < 10; ++i)
	{
		//Displays the position of the hand, and the corresponding domino
		if(player_hand[i])
		{
			cout<<"Hand Position "<<i<<endl;	
			player_hand[i]->display();
		}
	}

	cout<<endl;
}
	
			

//Shows the player's "score" of all the bones added up
void player::display_score()
{
	cout<<"Player score:"<<score<<endl<<endl;
}
