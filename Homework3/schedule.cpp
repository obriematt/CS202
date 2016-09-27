//Matthew O'Brien
//March 3rd 2015
//Assignment 3






//The file for the functions of the schedule program. These will simply call the previously created functions
//from the other classes. This is used as an umbrella for the rest of the classes. This way the maintest file
//only has to deal with one class, and it's more user friendly.

#include "schedule.h"


//Scheduler constructor
scheduler::scheduler()
{
}



//Scheduler destructor
scheduler::~scheduler()
{
}



//The welcome message to the program. States the information about what the program does, and how to properly use 
//it. Sort of the guidelines/how to for the program
void scheduler::welcome_message()
{
	cout<<"Welcome to the great and powerful scheduler!"<<endl;
	cout<<"This program will allow you to select a month for which you would like to make appointments."<<endl;
	cout<<"Currently, there is no way to differentiate between weekdays and weekends."<<endl;
	cout<<"You may select how many days you want to schedule for, and the month."<<endl;
	cout<<"The times are to be selected by military time, example 13 is 1pm."<<endl;
	cout<<"Please only select days and times that are available in the calendar."<<endl;
	cout<<"When adding an attendee please only use lower case."<<endl;
	cout<<"Happy scheduling."<<endl;
}



//Menu function. Gives the user a set of options to select from for scheduling.
void scheduler::menu_function()
{

	cout<<"1. Show the available appointments on the calendar."<<endl;
	cout<<"2. Add an attendeei, in lower case, to a given appointment."<<endl;
	cout<<"3. Show all current attendees."<<endl;
	cout<<"4. Quit this thing."<<endl;
}



//This will make the user specific calendar for scheduling appointments
//Takes in the bulk of information, and builds the LLL of LLL.
void scheduler::make_appointments(int start_days, int end_days, int start_time, int end_time, char * month_toadd)
{
	the_calendar.build_calendar(start_days, end_days, start_time, end_time, month_toadd);
}



//This will add an attendee to the BST and remove the possible appointment. Takes in a temp node, which 
//is copied and passed into the BST. Also uses the int values to remove from calendar.
void scheduler::add_attendee(node * to_add)
{
	bst.add(to_add);
	the_calendar.delete_time(to_add->get_day(), to_add->get_time());
} 	



//Show the attendees already scheduled
void scheduler::show_attendees()
{
	bst.display_all_wrap();
}



//Show the current calendar of available appointments
void scheduler::show_calendar()
{
	the_calendar.display_appointments();
}	
