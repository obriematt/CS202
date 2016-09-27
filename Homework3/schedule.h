//Matthew O'Brien
//Assignment 3
//March 3 2015




//The final header file. This class will be the container for the rest of the classes for the 
//scheduling program. It will handle the basic interaction with the user. Allowing for a display of 
//the calendar, to take in people's information, and to show those who already have appointments set up.



#include "person.h"


//The umbrella to the rest of the classes
class scheduler
{
	public:
		scheduler();
		~scheduler();
		void welcome_message();
		void make_appointments(int start_days, int end_days, int start_time, int end_time, char * month_toadd);
		void show_attendees();
		void add_attendee(node * to_add);
		void menu_function();
		void show_calendar();

	protected:
		appointment_list the_calendar;
		binary_tree bst;
};


