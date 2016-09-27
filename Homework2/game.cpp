//Matthew O'Brien

//Assignment 2





//This is the file for the game functions. I will be implementing all of the different functions utilized by the 
//game class. The idea here for sort of umbrella containing all of the other classes, and connecting them together.
//This will also contain the different menu functions for the game for each player. Keep track of the players scores,
//and declare a winner.


#include "game.h"




//Game constructor
game::game()
{
}



//Game destructor
game::~game()
{	

}




//First player's functions, options, and moves. Allows for playing bones, showing hand, and skipping their turn.
void game::player_goes(int num)
{
	int response = 0;
	do
	{
		//Shows the play options and gives them a number to pick from.
		cout<<"Player "<<num<<"'s turn. Please select from below"<<endl;
		player_options();
		cout<<endl;
		//Displays the player's hand
		display_player(num);
		cout<<endl;
		//The options to select from
		cout<<"Select 1 2 or 3: ";
		cin>>response;
		cin.ignore(100, '\n');
		if(response == 1)
		{
			//Very important. These positions will correspond to the position in the hand
			//and the position on the field the player wants to play.
			int hand_pos = 0;
			int board_pos = 0;
			cout<<endl;
			cout<<"What is the hand position of the bone? ";
			cin>>hand_pos;
			cin.ignore(100, '\n');
			cout<<"What is the board position you wish to play to? ";
			cin>>board_pos;
			cin.ignore(100, '\n');
			//Plays the bone in the manner selected above
			play_bone(num, board_pos, hand_pos);
			cout<<endl;
		}
		if(response == 2)
		{
			//Redisplays the player's hand. Just in case.
			display_player(num);
		}
		if(response == 3)
		{
			//Skips turn and draws a bone to the player. Can never have more then 10 tiles.
			draw_bone(num);
		}
		cout<<endl;
	}while(response == 2);
	//Repeats selection if the player looks at their hand again.
	
}

		


//Welcome message. yup. Welcome.
void game::welcome_message()
{
	cout<<"Welcome to the bones game."<<endl;
	cout<<"This is a 4 person game. Each player will be given 7 random bones."<<endl;
	cout<<"The game will then select the double tile that is the largest from those dealt to the players."<<endl;
	cout<<"This will be your starting point. Players have the option of playing from the starting point no more ";
	cout<<"then 4 times."<<endl;
	cout<<"After which, you must player off of a foot."<<endl; 
	cout<<"The goal is to rid yourself of all bones. There is a built in handicap of 10 bones per hand."<<endl;
	cout<<"You will have to draw a bone if you can not play."<<endl;
	cout<<"The lowest score at the end is the winner. GOODLUCK!"<<endl;
	cout<<endl;
	cout<<endl;
	//An extra note since the game doesn't check the bones properly. I ran out of time to get this implementation to work.
	cout<<"PLEASE NOTE: Currently there is no check system to make sure a bone is playable onto a side of the starting bone."<<endl;
	cout<<"		    For the sake of the game, please only play bones that correctly matching previous bones."<<endl;
}



//Player options to pick from.
void game::player_options()
{
	cout<<"1. Play bone of a given hand position."<<endl;
	cout<<"2. Display hand."<<endl;
	cout<<"3. Skip turn."<<endl;
}	



//This function will auto play the largest bone from all 4 players.
//It will place it into "position 0" or the starting double bone for
//the rest of the bones to be played from.
void game::starting_bone()
{
	int player_num = find_doubles();
	int hand_pos = players[player_num].double_position();
	play_bone(player_num, 0, hand_pos);
}





//Finds out which player has the largest double out of all the bones dealt.
//This function is only for the automatic play of the largest double dealt.
int game::find_doubles()
{
	int sum = 0;
	int position = 0;
	//Goes through the 4 players from the game
	for(int i=0;i<4;++i)
	{
		//If a double is larger then the previous double save over it.
		//Save the position of the player
		if(players[i].biggest_double() > sum)
		{
			sum = players[i].biggest_double();
			position = i;
		}	
	}
	//Returns the player position for the play_bone function
	return position;
}	




//Displays a player's hand.
void game::display_player(int num)
{
	cout<<"Player "<<num<<"'s hand."<<endl;
	players[num].display_hand();
	players[num].display_score();
}



//Deals out the initial 7 bones to each player
void game::deal_hands()
{
	//goes through the 4 players
	for(int j=0; j<4;++j)
	{
		//Gives them 7 bones from the pile. The pile should be randomized
		for(int i=0; i<7; ++i)
			players[j].draw_bone(*my_pile.pop_bone());
		//Sets the players initial score
		players[j].set_score();
	}
	
}



//Used to draw a single bone. For when a player skips their turn for being unable to play.
void game::draw_bone(int num)
{
	players[num].draw_bone(*my_pile.pop_bone());
}


//Wrapper function to initialize the deck
void game::make_new_deck()
{
	my_pile.make_new_deck();
}



//Displays the deck. Testing purposes only
void game::display_deck()
{
	my_pile.display_deck();
}


//Wrapper for shuffling the deck to the pile.
void game::shuffle()
{
	my_pile.shuffle();
}



//Test wrapper function to make sure the deck is shuffled.
void game::display_shuffled()
{
	my_pile.display_shuffled();
}



//Plays a bone from a given player, to a given field position from a given position in the players hand
void game::play_bone(int player_num, int field_pos, int hand_pos)
{

	bone * temp = players[player_num].play_bone(hand_pos);
	my_field.add_bone(field_pos, *temp);
	players[player_num].delete_bone(hand_pos);	
	
}


//Displays the overall board. Given by positions numbered on the board for previous functions.
void game::show_board()
{
	my_field.display_ends();
}



//Gets the player's score to check if anyone has hit zero. At which point the game ends.
int game::check_score(int num)
{
	return players[num].get_score();
}	 
	

