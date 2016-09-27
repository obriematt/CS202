//Matthew O'Brien
//Jan 30th 2015
//Assignment 1



//File containing the prototypes for the bone class and subclasses.
//These classes will contain the information for each of the bones that will be passed around 
//throughout the game. The bone class is mostly setters/getters which was suppose to be avoided
//but I was unable to get any other method working. So I stuck with what worked.

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


//Constants that are used in other classes for simplicity towards design
const int MAX = 45;
const int index_max = 5;

class bone
{

	public:
		bone();
		~bone();
		int get_value1();
		int get_value2();
		void set_value1(int num);
		void set_value2(int num);
		void display();
		void copy_bone(bone& to_copy);
		bone * next_ptr();
		void set_next(bone * ptr);
		bool double_check();
		int get_sum();
	protected:
		int value1;
		int value2;
		bone * next;
};


//Regular bone class. Used for the non doubles
class regular_bone: public bone
{
	public:
		regular_bone();
		~regular_bone();
		void display();
	protected:
		int bone_sum;
};


//Double bone class. Will be used for the field to determine if a 
//"chicken foot" needs to be created on the field.
class double_bone: public regular_bone
{

	public:
		double_bone();
		void display();		
		~double_bone();
		bone * up_ptr();
		bone * down_ptr();
	protected:
		bone * up;
		bone * down;

};


