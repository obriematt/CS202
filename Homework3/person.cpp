//Matthew O'Brien
//March 3rd 2015
//Assignment 3





//The functions of the person header file are contained here. This includes the person and node classes. 
//Which will be people input by the user, allowing for a selection of their names, which will be fed into
//the BST structure for the attendees. 





#include "person.h"


//person constructor
person::person()
{
	first_name = NULL;
	last_name = NULL;

}



//Person destructor
person::~person()
{
	delete [] first_name;
	delete [] last_name;
}



//Copy constructor for the person class
person::person(const person & steve)
{
	copy_person(steve);
}




//Returns the time for a given person
int person::get_time()
{
	return time;
}



//Returns the day for a given person
int person::get_day()
{
	return day;
}




//Copy function for the person class. Also used by the copy constructor.
//Split into different functions just in case the copy is needed elsewhere.
void person::copy_person(const person & to_copy)
{
	//Read in new first name
	first_name = new char[strlen(to_copy.first_name)+1];
	strcpy(first_name, to_copy.first_name);
	//Read in new last name
	last_name = new char[strlen(to_copy.last_name)+1];
	strcpy(last_name, to_copy.last_name);
	//Simple ints for day and time.
	day = to_copy.day;
	time = to_copy.time;
}
	


//equals operator overloaded function
node& node::operator= (const node& steve)
{
	//If they are the same, return
	if(this == &steve)
		return *this;
	//Clean up what's there, if there is anything.
	if(first_name)
		delete [] first_name;
	if(last_name)
		delete [] last_name;
	
	//Probably should have just called the copy function here.
	//Does the same thing, but in the interest of my working program, i did not change it.
	first_name = new char[strlen(steve.first_name)+1];
	strcpy(first_name, steve.first_name);
	last_name = new char[strlen(steve.last_name)+1];
	strcpy(last_name, steve.last_name);
	
	day = steve.day;
	time = steve.time;
	left = steve.left;
	right = steve.right;
	return *this;
}	



//Overloaded operator for the <<
//Simply just a display function.
ostream& operator<<(ostream& out, const person& steve)
{
	cout<<"First name: "<<steve.first_name<<endl;
	cout<<"Last name: "<<steve.last_name<<endl;
	cout<<"Date of appointment: "<<steve.day<<endl;
	cout<<"Time of appointment: "<<steve.time<<endl;
}



//Add a person's information. Used for the temp nodes in my maintest file.
void person::add_person(char * first, char * last, int add_day, int add_time)
{

	first_name = new char[strlen(first)+1];
	strcpy(first_name, first);

	last_name = new char[strlen(last)+1];
	strcpy(last_name, last);
	
	day = add_day;
	time = add_time;
}




//Node constructor.
node::node()
{
	left = NULL;
	right = NULL;
}



//Copy constructor for the node class. Just calling the copy constructor for person
node::node(const node& steve)
{
	left = steve.left;
	right = steve.right;
	copy_person(steve);
}


//Node destructor
node::~node()
{
		
}



//The go left function, returns the left pointer.
node* node::go_left()
{
	return left;
}



//The go right function, returns the right pointer.
node* node::go_right()
{
	return right;
}


//Making a connection to the right
void node::connect_right(node * connect)
{
	right = connect;
}



//Making a connection to the left 
void node::connect_left(node * connect)
{
	left = connect;
}




//compare the nodes' names
void node::add_nodes(node * to_check)
{
	//temp int values for comparison
	int check_num = 0;
	int current_num = 0;
	
	//Set the first initial of the last name to an int value
	check_num = to_check->last_name[0];
	current_num = last_name[0];

	//Sets last name in alphabetical order
	if(check_num < current_num)
	{
		//If left isn't null go left, or add left
		if(left != NULL)
		{
			left->add_nodes(to_check);
		}
		else
			left = new node(*to_check);
	}
	else
	{
		//if right isn't null go right, or add right.
		if(right != NULL)
		{
			right->add_nodes(to_check);
		}
		else
			right = new node(*to_check);
	}

	
}
		



//binary_tree constructor
binary_tree::binary_tree()
{
	root = NULL;
}


//tree destructor
binary_tree::~binary_tree()
{
	remove_all(root);
}



//Recursively delete the BST. Used by the destructor. Could be used in implementation to remake the calendar
//This was not implemented but could be for future use.
void binary_tree::remove_all(node * root)
{
	//If there is no root, return
	if(!root)
		return;
	//Recursion
	remove_all(root->go_left());
	remove_all(root->go_right());
	delete root;
	root = NULL;
	return;
}



//Display the full tree of people and appointments
void binary_tree::display_all(node*root)
{
	//No tree, return
	if(!root)
		return;
	//Recursion to display in alphabetical order
	display_all(root->go_left());
	cout<<*root;
	display_all(root->go_right());
	return;
}



//Wrapper function to display all
void binary_tree::display_all_wrap()
{
	display_all(root);
}


//Adds a node/person to the BST
void binary_tree::add(node * to_add)
{

	if(!root)
		root = to_add;
	else
		root->add_nodes(to_add);

}		
