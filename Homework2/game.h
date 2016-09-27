//Mathew O'Brien

//Assignment 2






//The h file containing my game class. This is the class that will contain the rest of the classes. It will
//act as the link between the pile, field, and players. It will allow the "players" to actually play the game.
//It will control which player is currently going, as well as creating the amount of players that the game needs,
//ranging from 2-4. It will also check the hands of each player for the largest double bone and play it on the field
//automatically. 



#include "field.h"


class game
{

	public:
		game();
		~game();
		void welcome_message();
		void player_options();
		void show_board();
		void deal_hands();
		void draw_bone(int num);
		void player_goes(int num);
		void play_bone(int player_num, int position, int hand_pos);
		void make_new_deck();
		void display_deck();
		void shuffle();
		void display_shuffled();
		void display_player(int num);
		int find_doubles();
		void starting_bone();
		int check_score(int num);
	protected:
		player players[4];
		field my_field;
		pile my_pile;
};
