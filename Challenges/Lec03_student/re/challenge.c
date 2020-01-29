#include "challenge.h"

// Creates a Time struct given the hour, minute, and second
//   param hour: int representing the hour 0-23
//   param min: int representing the minute 0-59
//   param sec: int representing the second 0-59
//   return: a Time struct for the time representing the same time as the integers
// TODO: complete the function
struct Time create_time(int hour, int min, int sec)
{
	struct Time create = {hour,min,sec};
  return create;
}

// Gets the hour from a Time struct
//   param t: struct representing a time
//   return: an int representing the hour of time t
// TODO: complete the function
int get_hour(struct Time t)
{
  return t.hour;
}

// Gets the minute from a Time struct
//   param t: struct representing a time
//   return: an int representing the minute of time t
// TODO: complete the function
int get_min(struct Time t)
{
  return t.minute;
}

// Gets the second from a Time struct
//   param t: struct representing a time
//   return: an int representing the second of time t
// TODO: complete the function
int get_sec(struct Time t)
{
  return t.second;
}

// TODO: complete the function
void set_hour(struct Time* t, int hour)
{
	t->hour = hour;
}

// TODO: complete the function
void set_min(struct Time* t, int min)
{
	t->minute = min;
}

// TODO: complete the function
void set_sec(struct Time* t, int sec)
{
	t->second = sec;
}

// Creates a Time struct representing the difference between two times
//   param t1: Time struct representing the beginning of interval
//   param t2: Time struct representing the end of interval
//   return: Time struct representing time between t1 and t2
// TODO: complete the function
struct Time elapsed_time(struct Time t1, struct Time t2)
{
	int t1S = t1.hour*60*60 + t1.minute*60 + t1.second;
	int t2S = t2.hour*60*60 + t2.minute*60 + t2.second;
	int sol = t2S - t1S;
	if(sol<0){sol = 86400+sol;
		
	}
	struct Time fin = { sol/3600, (sol - (sol/3600)*3600)/60, ((sol - (sol/3600)*3600) - (((sol - (sol/3600)*3600)/60)*60)  ) };
	
  return {fin};
}
