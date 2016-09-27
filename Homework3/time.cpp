//Matthew O'Brien
//Assignment 3
//March 3rd 2015



//The functions for my classes for the "time" specific portions of the program.
//All of these functions deal with the avaliable appointments within a given calendar month of 28 days.
//Each day will only have one appointment available per hour from 9 to 5, a normal business day. There
//are no special considerations for weekends and weekdays. Days will be automatically populated with the times.

#include "person.h"



//Time slot class constructor. Setting next to null, the int isn't needed to set for this.
time_slot::time_slot()
{
	next_time = NULL;
}



//The time slot destructor
time_slot::~time_slot()
{
	next_time = NULL;	
		
}


//Date slot constructor!
date_slot::date_slot()
{
	next_date = NULL;
	head_time = NULL;
}


//Date slot DESTRUCTOR!
date_slot::~date_slot()
{
	time_slot * current;
	current = head_time;
	while(head_time)
	{
		head_time = head_time->get_next();
		delete current;
		current = NULL;
		current = head_time;
	}
	delete head_time;
	head_time = NULL;
}



//Appointment list constructor
appointment_list::appointment_list()
{
	month = NULL;
	head_date = NULL;
}



//Appointment list destructor
appointment_list::~appointment_list()
{
	delete [] month;
	month = NULL;
	date_slot * current = head_date;
	
	while(head_date)
	{
		head_date = head_date->get_next_date();
		delete current;
		current = NULL;
		current = head_date;

	}
	delete head_date;
	head_date = NULL;			
}


//Set date function.
void date_slot::set_date(int date_toadd)
{
	dates = date_toadd;
}



//Get date function
int date_slot::get_dates()
{
	return dates;
}



//Get next pointer for dates list
date_slot* date_slot::get_next_date()
{
	return next_date;
}



//Set next pointer for date list
void date_slot::set_next(date_slot* ptr)
{
	next_date = ptr;
}

//Sets the time for the given time slot.
void time_slot::set_time(int time)
{
	times = time;
}



//Retrieves a given time.
int time_slot::get_time()
{
	return times;
}


//get the next pointer for the time slots.
time_slot* time_slot::get_next()
{
	return next_time;
}



//set the next pointer for the time slots
void time_slot::set_next(time_slot * ptr)
{
	next_time = ptr;
}	


//The auto fill function to set each day to have appointments from 9 to 5 military time.
//On the top of every hour.
void date_slot::auto_fill_times(int start_time, int end_time)
{
	//Temp int to increase when building the calendar
	int times_toset = start_time;
	time_slot * temp;

	//Make a new head if there isn't one. Which there shouldn't be.
	if(!head_time)
	{
		head_time = new time_slot;
		//Adds the start time
		head_time->set_time(times_toset);
	}
	//make the rest of the calendar
	while(start_time < end_time)
	{
		++start_time;
		temp = new time_slot;
		temp->set_next(head_time);
		//Adds the start time
		temp -> set_time(start_time);
		head_time = temp;		

	} 
}



//Builds the full calendar of possible appointments for each day.
void appointment_list::build_calendar(int start_days, int end_days, int start_time, int end_time, char * month_toadd)
{
	
	//Read in the month the user wants
	month = new char[strlen(month_toadd)+1];
	strcpy(month, month_toadd);

	//Check for a head, and add a new date slot if there isn't one. Which there shouldn't be
	if(!head_date)
	{
		head_date = new date_slot;
		head_date->set_date(start_days);
		head_date->auto_fill_times(start_time, end_time);
	}
	
	//Make the rest of the days
	while(start_days <= end_days)
	{
		//new date slot temp
		date_slot * temp = new date_slot;
		//Fills each day with time slots from start to end
		temp->auto_fill_times(start_time, end_time);
		temp->set_next(head_date);
		head_date = temp;
		temp->set_date(start_days);
		++start_days;
	}
}
		



//Display the full available calendar
void appointment_list::display_appointments()
{
	//Check for the list
	if(!head_date)
		return;
	//Temp current ptr to traverse
	date_slot * current = head_date;
	cout<<"For the Month of "<<month<<" times are available:"<<endl;
	//Loop for display	
	while(current->get_next_date())
	{
		//I realized a little late, this would be a great place for an overloaded operator <<
		//Due to time, it just stays like this.
		current->display_times();
		current = current->get_next_date();
	}
}
		
		

//Displays the times left for a given day to grab as an appointment
void date_slot::display_times()
{
	//Temp ptr
	time_slot * current;
	current = head_time;
	
	//No times left for that day.
	if(!head_time)
	{
		cout<<"There are no more times left for "<<dates<<endl;
		return;
	}

	//If there is only one time left for that day.
	if(!head_time->get_next())
	{
		cout<<"The available time for the "<<dates<<" is: ";
		cout<<head_time->get_time()<<endl;
		return;
	}

	//Displays times of the day if more then one is still open.
	cout<<"The available times for the "<<dates<<" are the follow: ";	
	while(current)
	{
		cout<<current->get_time()<<" ";
		current = current->get_next();
	}
	cout<<endl;
}	


	
//Used to remove a time from a date when it is selected by the user
int date_slot::delete_time_slot(int time_to_delete)
{	
	//Check for head, return if not.
	if(!head_time)
		return 0;
	
	//Temp ptrs for traversal
	time_slot * current = head_time;
	time_slot * previous;

	//If the first one is the match, special case
	if(current->get_time() == time_to_delete)
	{
		head_time = head_time -> get_next();
		delete current;
		current = NULL;
		return 1;
	}

	//Traversal deleting from elsewhere in the list.
	while(current -> get_next())
	{
		previous = current;
		current = current -> get_next();
		if(current->get_time() == time_to_delete)
		{
			previous -> set_next(current -> get_next());
			delete current;
			current = NULL;
			return 1;
		}
	}
	return 0;
}



//Removing the time slot from the calendar when selected
void appointment_list::delete_time(int delete_day, int delete_time)
{
	//Checking for a list
	if(!head_date)
		return;
	
	//Temp ptrs for deletion
	date_slot * current = head_date;
	time_slot * previous;

	//If the first node is a match. special case
	if(current->get_dates() == delete_day)
	{
		//Gotta delete the time slot.
		current->delete_time_slot(delete_time);
		return;
	}
	//Anywhere else in the list of things.
	while(current->get_next_date())
	{
		//Moving along.
		current = current -> get_next_date();
		if(current->get_dates() == delete_day)
		{
			//Deleting the time slot
			current->delete_time_slot(delete_time);
			return;
		}
	}
	return;
}
