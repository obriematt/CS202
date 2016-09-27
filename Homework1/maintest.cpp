//Matthew O'Brien
//Jan 30th 2015
//Assignment 1




//A sort of a test function to show the interaction between the bone, pile, and the player classes. There won't be any real "game" within this file as that is for assignment 2. This is only to show the functionality of the classes already made for this assignment.


//I didn't implement a sort of function for you to sort through with a menu. It honestly seemed like a waste of time for me to do that, since later all of that will be handled by the game class.
//Hopefully you don't mind that this is just one giant output whenever you run it. All of the functions are commented for what they do, as well as cout messages for the output to see the different
//roles that each of those functions will play later on.


//You can re-run this program a few times to show that the shuffle is actually random

#include "player.h"


using namespace std;


int main()
{
	//This was bad code. Left it just in case I needed to remind myself what not to do.

//	bone * bone_array[MAX];

//	bone_array[MAX] -> populate_bones(0, bone_array);
//	cout<<endl;	

//	for(int i = 1; i < MAX; i++)
//	{
//		cout<<"Tile Number:"<<i<<" "<<bone_array[i]->get_value1()<<bone_array[i]->get_value2()<<" ";
//	}
//	cout<<endl;

	//Created 4 players 
	//This will be done later on by the game class with a different amount of players allowed. 
	//I just built this in for testing purposes
	
	player player_1;
	player player_2;
	player player_3;
	player player_4;
	
	//Making a chickenyard from the pile class
	pile chicken_yard;
	
	//This makes the initial deck in a sorted order. This way I can check for accidental doubles.
	chicken_yard.make_new_deck();
	
	//This displays the sorted deck. Again a error check.
	cout<<endl;
	cout<<"DECK IN SORTED ORDER!"<<endl;
	chicken_yard.display_deck();
	
	//Shuffles the deck into the chickenyard
	chicken_yard.shuffle();

	//This will display the sorted deck. Again for testing purposes. 
	//Obviously in the game I do not want to do this as it would be cheating.
	cout<<endl;
	cout<<"THIS IS THE SHUFFLED DECK!"<<endl;
	chicken_yard.display_shuffled();
	
	
	//The following function calls are to test each player's hand and score.
	cout<<endl;
	cout<<"PLAYER TEST!";
	cout<<endl;


	//This functions will be implemented within the player class later on when the game class in made.
	//My game class will have a "has a" relationship with the other classes allowing for the player class function
	//of dealing a full hand out rather then this loop. 
	//this was only implemented for testing.
	cout<<"Player 1!"<<endl;
//	player_1.create_hand();
//	for(int i = 0; i < 10; ++i)
	for(int i = 0; i < 7; ++i)
		player_1.draw_bone(*chicken_yard.pop_bone());

	player_1.display_hand();
	player_1.display_score();

	cout<<"Player 2!"<<endl;
	for(int i = 0; i < 7; ++i)
		player_2.draw_bone(*chicken_yard.pop_bone());
	player_2.display_hand();
	player_2.display_score();

	cout<<"Player 3!"<<endl;
	for(int i = 0; i < 7; ++i)
		player_3.draw_bone(*chicken_yard.pop_bone());
	player_3.display_hand();
	player_3.display_score();

	cout<<"Player 4!"<<endl;
	for(int i = 0; i < 7; ++i)
		player_4.draw_bone(*chicken_yard.pop_bone());
	player_4.display_hand();
	player_4.display_score();


	//My happy message at the end.
	cout<<"OHMAHGAWD DID IT WORK!?"<<endl;	
//	player_1.draw_bone(*chicken_yard.pop_bone());	
	
//	bone * ptr = chicken_yard.pop_bone();
//	cout<<ptr->get_value1();
	
	return 0;
}
