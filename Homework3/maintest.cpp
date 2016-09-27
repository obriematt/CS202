//Matthew O'Brien
//Assignment 3
//March 3 2015




//The main test file for my assignment as the name suggests.
//This is where I test my code, and the finally working program will
//be used.



#include "schedule.h"

//constant int for the temp chars. Hopefully no name is over a length of 15.
const int size = 15;

int main()
{
	//Variables
	scheduler the_schedule;
	//temp info for calendar
	char month[size];
	int s_day;
	int e_day;
	int s_time;
	int e_time;
	int response;
	//welcomes you.
	the_schedule.welcome_message();
	
	//Start collecting information
	cout<<"What month are we adding? ";
	cin.get(month, size, '\n');
	cin.ignore(100, '\n');

	cout<<"Starting day: ";
	cin>>s_day;
	cin.ignore(100, '\n');

	cout<<"Ending day: ";
	cin>>e_day;
	cin.ignore(100, '\n');
	
	cout<<"Starting time: ";
	cin>>s_time;
	cin.ignore(100, '\n');

	cout<<"Ending time: ";
	cin>>e_time;
	cin.ignore(100, '\n');
	//Makes the calendar
	the_schedule.make_appointments(s_day, e_day, s_time, e_time, month);
	//Do/while loop for adding attendees, displaying appointments and the calendar.
	//input 1-3 for options, 4 for quit.
	do
	{
		the_schedule.menu_function();
		cin>>response;
		cin.ignore(100, '\n');
	
		//Shows calendar
		if(response == 1)
		{
			the_schedule.show_calendar();
		}
		//reads in a temp attendee to a node, copied into the tree
		if(response == 2)
		{
			char month[size];
			char first[size];
			char last[size];
			int add_day;
			int add_time;
			node * person_toadd = new node;
			cout<<"Your first name: ";
			cin.get(first, size, '\n');
			cin.ignore(100, '\n');
			cout<<"Your last name: ";
			cin.get(last, size, '\n');
			cin.ignore(100, '\n');
			cout<<"What day: ";
			cin>>add_day;
			cin.ignore(100, '\n');
			cout<<"What time: ";
			cin>>add_time;
			cin.ignore(100, '\n');
			person_toadd->add_person(first, last, add_day, add_time);
			the_schedule.add_attendee(person_toadd);
		}
		//Shows the BST
		if(response == 3)
		{
			the_schedule.show_attendees();
		}	
	}while(response == 1 || response == 2 || response == 3);

	return 0;
}
