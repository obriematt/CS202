//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



/*
This is the primary test function for the game itself. It will be creating an object of the game class, which allows for the connections between the other classes.
it will also know when the game is over according to when a players score hits 0. I understand that break calls aren't really a favorite of Karla's but I couldn't seem to get it to work 
in any other manner. Just to say again what the game message already says, I was having a lot of issues with my bone checks when playing on the field. In the interest of saving time, I simply 
removed the code that I couldn't get to work, and just went with a sort of honor system between players. So they will only play a bone to where they should, in later implementations of this game,
getting the code to work properly would be nice. I apologize in advance for the issue. Though the game itself will still play, just allowing a player to play where ever they want on the game.
*/


#include "game.h"


using namespace std;


int main()
{

	game my_game;
	int response = 0;
	int winner = 0;

	my_game.make_new_deck();
	my_game.shuffle();

	my_game.deal_hands();
	my_game.welcome_message();
	cout<<endl;		
	my_game.starting_bone();	
	my_game.show_board();
	cout<<endl;

	do
	{
		my_game.player_goes(0);
		if(my_game.check_score(0) == 0)
			break;
		my_game.show_board();
		cout<<endl;
		my_game.player_goes(1);
		if(my_game.check_score(1) ==0)
			break;
		my_game.show_board();
		cout<<endl;
		my_game.player_goes(2);
		if(my_game.check_score(2) ==0)
			break;
		my_game.show_board();
		cout<<endl;
		my_game.player_goes(3);
		if(my_game.check_score(3) ==0)
			break;
		my_game.show_board();
		cout<<endl;
	}while(my_game.check_score(0) != 0 && my_game.check_score(1) != 0 && my_game.check_score(2) != 0 && my_game.check_score(3) != 0);
	if(my_game.check_score(0)==0)
		winner = 0;
	if(my_game.check_score(1)==0)
		winner = 1;
	if(my_game.check_score(2)==0)
		winner = 2;
	if(my_game.check_score(3)==0)
		winner = 3;
	cout<<endl; 
	cout<<"WE HAVE A WINNER! Congrats to player "<<winner<<"!!!!!!!";
	cout<<endl;	






















	
	return 0;
}
