//Matthew O'Brien
//March 3rd 2015
//Assignment 3





//Header file for the classes involved with the person's information and BST. 
//The node is a person, while the node handles the BST functionality of the
//program, the person class will handle each attendee's information. 
//The person class will have a pointer to a time_slot class as well. This allows
//for each person to sign up for a time slot, and possibly even more if they feel like it. 
//Since there is only one month being created for this
//assignment, there won't be any information displayed about the month, 
//but can be altered later if more time is added.


//Use of operator overloading in this class. I chose not to use the + or += for the LLL and BST.
//Mostly because I was having issue making it work, and I felt like the copy constructor 
//handled the problem in a much easier fashion.

#include "time.h"


//The person, or the attendee for a given appointment.
class person
{
	public:
		person();
		person(const person& steve);
		~person();
		void copy_person(const person& to_copy);
		void add_person(char * first, char * name, int add_day, int add_time);
		friend ostream& operator<<(ostream& out, const person& steve);
		int get_day();
		int get_time();		
	protected:
		char * first_name;
		char * last_name;
		int day;
		int time;
};


//Class to handle functionality with the BST. Node is a person
class node: public person
{
	public:
		node();
		node(const node& steve);
		~node();
		node* go_left(); 
		node* go_right();
		void connect_left(node * connect);
		void connect_right(node * connect);
		void add_nodes(node * to_check);
		node& operator= (const node& steve);
	
	protected:
		node * left;
		node * right;
};

//Binary tree has a node.
class binary_tree
{
	public:
		binary_tree();
		~binary_tree();
		void display_all(node*root);
		void display_all_wrap();
		void remove_all(node * root);
		void add(node * to_add);

	protected:
		node * root;
};











