//Matthew O'Brien

//March 3rd 2015
//Assignment 3


//The header file for the "Time" portion of the assignment. This will contain the day, and time slot information for the program.
//This is the LLL of LLL. Each day is a node of the first LLL which then contains the available time slots for the day.


#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Class to control and keep the time slots of a given day. These functions will auto fill the day with time slots, remove a time slot when someone selects it, and a display function to show the times open
//for a given day.
class time_slot
{
	public:
		time_slot();
		~time_slot();
		void set_time(int time);
		int get_time();
		time_slot * get_next();
		void set_next(time_slot*ptr);
	protected:
		int times;
		time_slot * next_time;
};

//These are the days available for someone to select from. 
//No difference between a weekday and weekend. All days will be treated as equal.
class date_slot
{
	public:
		//Constructor and Destructor
		date_slot();
		~date_slot();

		//Basic functions
		int delete_time_slot(int time_to_delete);
		void display_times();
		void auto_fill_times(int start_time, int end_time);

		
		//Set and Get. Not OOP
		void set_date(int date_toadd);
		int get_dates();
		date_slot* get_next_date();
		void set_next(date_slot* ptr);	
		
	protected:
		int dates;
		date_slot * next_date;
		time_slot * head_time;
};


//The overall container for the other two LLL. This will act as a sort of "month". This also allows for further implementation to make a month to month scheduling program.
//If it was required, additional functionality to show each month could be added. But for simplicity sake, and mine, there will only be one month. 
class appointment_list
{
	public:
		appointment_list();
		~appointment_list();
		void display_appointments();
		void build_calendar(int start_days, int end_days, int start_time, int end_time, char * month_toadd);
		void delete_time(int delete_day, int delete_time);
	protected:
		char * month;
		date_slot * head_date;
};
