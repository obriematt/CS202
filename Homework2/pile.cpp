//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



//File containing the functions for the pile of tiles.
//This will also contain the node for the LLL of array's required for the pile.
//In retrospect, it might have been better to split these two up, this file is very cluttered.
#include "pile.h"
#include <iostream>

using namespace std;



//Node Constructor for node of LLL of arrays or the chicken yard
node::node()
{
	for(int i = 0; i < 5;++i)
	{
		b_array[i] = NULL;
	}
	next = NULL;
}


//Node Destructor for LLL of arrays or the chicken yard
node::~node()
{
	destroy_array();
	next = NULL;

}



//Constructor for the pile or chicken yard
pile::pile()
{
	top_index = 0;
	head = NULL;
	for(int i=0; i < MAX; i++)
		bone_array[i] = NULL;
}



//Destructor for the pile/chicken yard
pile::~pile()
{
	//Goes through the array in the pile and deletes
	for(int i = 0; i < MAX; ++i)
	{
		delete bone_array[i];
		bone_array[i] = NULL;
	}
	//Moves to the next array and deletes
	while(head)
	{
		node * current = head;
		head->destroy_array();
		head = head->get_next_ptr();
		delete current;
		current = NULL;
	}
						

}



//Destroy function to remove and delete the array within a node for the chicken yard. Split this one out
//just in case it becomes useful else where.
void node::destroy_array()
{
	//Goes through the array of bones in the node and deletes
	for(int i = 0; i < 5; ++i)
	{
		delete b_array[i];
		b_array[i] = NULL;
	}
}



//Gets the index of the array within the nodes. Useful to pass information around between classes
int pile::get_index()
{
	return top_index;
}


//Get function for the next pointer of the node.
node * node::get_next_ptr()
{
	return next;
}



//Set function for the next pointer of the node.
void node::set_next_ptr(node * ptr)
{
	next = ptr;
}


//Adds a bone to the stack at a given position from the deck.
void node::add_bone(int num, bone & to_copy)
{
	b_array[num] = new bone;
	b_array[num]->copy_bone(to_copy);
}	


//Pushes a bone onto the stack from the deck. Calls the add_bone function. Split
//for uses in multiple places and to clean up code.
void pile::push_bone(bone & to_copy)
{
	//Creates new node when current node is either not there or full.
	if(!head || top_index == index_max)
	{
		node * temp = new node;
		top_index = 0;
		temp->add_bone(top_index, to_copy);
		++top_index;
		temp->set_next_ptr(head);
		head = temp;
		return;
	}
	//Non full node, just adds to next spot
	head->add_bone(top_index, to_copy);
	++top_index;
}



//Returns a bone pointer at a given position in an array
bone * node::get_bone(int num)
{
	return b_array[num];
}


//Pops a bone off of the stack, returns it's pointer to be passed and copied into a player hand.
bone * pile::pop_bone()
{
	//Check the pile
	if(!head)
		return NULL;
	//Check the current index of the pile
	if(top_index == 0)
	{
		node * current = head;
		//Moves through the nodes
		if(head->get_next_ptr())
		{
			head = head->get_next_ptr();
			delete current;
			top_index = index_max - 1;
			return head->get_bone(top_index);
		}
		else
			return NULL;
	}
	//decrements down
	--top_index;
	//returns the bone pointer for copy
	return head->get_bone(top_index);
}



//Displays the shuffled deck. It displays the stack of bones. Testing purposes only.					
void pile::display_shuffled()
{
	node * current = head;
	//Checking to see if it's there
	if(!current)
		return;
	do
	{
		//Moving through the nodes
		for(int i = 0; i < 5; ++i)
		{
			current->get_bone(i)->display();
		}
		current = current->get_next_ptr();
	}while(current);
}
	


//Reads in the deck from the larger array into the stack in a shuffled order.
void pile::shuffle()
{
	int k = 0;

	//Seeds the random function
	srand(time(NULL));
	do
	{
		//Random int i generated and used from the deck creation to add to the pile
		int i = rand() % 45;
		if(bone_array[i])
		{
			//pushes the bone onto the pile
			push_bone(*bone_array[i]);
			++k;
			delete bone_array[i];
			bone_array[i] = NULL;
		}
		
	}while(k < 45); //Coded to not pass the total amount of tiles.
}


//This function makes a new deck of bones to be shuffled.
//This function is by far the most ugly piece of nonsense i've made since CS162.
//I couldn't figure out the nested for loops for this to be cleaner. And I didn't want to just ask
//someone for the code. So I apologize right now for how terrible this is, but it works.


//I wasn't able to change this from assignment 1. Honestly this function plagued me during the whole process.
void pile::make_new_deck()
{
	int j = 0;	
	//Makes the entire array for the deck to be initialized
	for(int i = 0; i < MAX; ++i)
		bone_array[i] = new bone;
	//for the bones holding a value of 1 and varying second
	for(int k = 1; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(1);
		++j;
	}	
	//For the bones with 2 and a varying second
	for(int k = 2; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(2);
		++j;
	}
	//Bones with a 3 and varying second
	for(int k = 3; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(3);
		++j;
	}
	//Value1 is 4 and a verying second value
	for(int k = 4; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(4);
		++j;
	}
	//Value1 is 5 and a varying second value
	for(int k = 5; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(5);
		++j;
	}
	//Value1 is 6, and value2 varies
	for(int k = 6; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(6);
		++j;
	}
	//Value1 is 7, and value2 varies
	for(int k = 7; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(7);
		++j;
	}
	//Value1 is 8 and value2 varies
	for(int k = 8; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(8);
		++j;
	}
	//Final bones are made.
	for(int k = 9; k < 10; ++k)
	{
		bone_array[j]->set_value1(k);
		bone_array[j]->set_value2(9);
		++j;
	}
}
	
//Displays the deck of cards in order for testing purposes	
void pile::display_deck()
{
	for(int i = 0; i < MAX; ++i)
	{

		bone_array[i]->display();
	}
}		
