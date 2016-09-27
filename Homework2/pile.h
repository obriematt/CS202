//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



//This file will contain the prototypes for the pile or deck of bones.


#include "bone.h"


//This class is for the node of the LLL of arrays.
//Contains a pointer to the next, and an array for each
//node.
class node
{
	public:
		node();
		~node();
		int get_value1();
		int get_value2();
		void set_value1(int num);
		void set_value2(int num);
		void add_bone(int num, bone & to_copy);
		node * get_next_ptr();
		void set_next_ptr(node * ptr);
		bone * get_bone(int num);
		void destroy_array();
		
	protected:
		node * next;
		bone * b_array[5];
};


//This is the "Chicken yard" I wanted to call it pile
//since I kept referring to it as a pile of bones when
//I was planning my program
class pile
{

	public:
		pile();
		~pile();
		void shuffle();
		void display_shuffled();
		void make_new_deck();
		void display_deck();
		bone * pop_bone();
		void push_bone(bone & to_copy);
		int get_index();
		
	protected:
		int top_index;
		node * head;
		//This array is for the deck creation
		bone * bone_array[MAX];	
};

				
