//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



//File containing the functions for the bone class. It will contain the functios
//for the double_bone class as well, but that is more for the interactions
//with the field, and playing the game. So I'm holding off on those for now.



#include "pile.h"

//bone constructor. Since a bone is only two ints and no dynamic memory, nothing was needed here.
bone::bone()
{

}


//Copy constructor that I ended up not using. Keeping this for Assignment 2 so I can implement and use it properly.
bone::bone(const bone & to_copy)
{
//	copy_bone(to_copy);

}


//Bone destructor. Again only two ints, no dynamic memory
bone::~bone()
{
}


//Copys a bone passed in using a set value function.
void bone::copy_bone(bone & to_copy)
{
	set_value1(to_copy.get_value1());
	set_value2(to_copy.get_value2());
}	


//Displays my bone in a readable manner. Should look like a domino
void bone::display()
{
	cout<<"["<<value1<<" | ";
	cout<<value2<<"]";
	cout<<endl;
}
	

//Getter functon for value1 of a bone
int bone::get_value1() 
{
	return value1;
}



//Getter function for the value2 of a bone.
int bone::get_value2()
{
	return value2;
}


//Sets an int passed in to the bone's value1
void bone::set_value1(int num)
{

	value1 = num;
}


//Sets an int passed in to the bone's value2
void bone::set_value2(int num)
{
	value2 = num;
}
	

	
