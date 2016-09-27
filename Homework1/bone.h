//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



//File containing the prototypes for the bone class and subclasses

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int MAX = 45;
const int index_max = 5;



//Bone class. It's a bone. It's got numbers.
class bone
{
	public:
		bone();
		bone(const bone & to_copy);
//		void populate_bones(bone * bone_array[]);
		int get_value1();
		int get_value2();
		void set_value1(int num);
		void set_value2(int num);
		~bone();
		void display();
		void copy_bone(bone & to_copy);
	protected:
		int value1;
		int value2;
};


//This was meant to be implemented in to determine
//if a bone was a double or not.
//Realized that I needed to change this a lot.
//As well as add a "regular" bone class.
//I plan on changing the bone classes around for the 
//actual implementation of the game.
class double_bone: public bone
{

	public:
		double_bone();
		double_bone(const double_bone & to_copy);
		~double_bone();
	protected:

};


