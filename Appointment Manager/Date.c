#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <stdio.h>
#include <time.h> 
//Date Implementation To Show Earliest Day A Customer Can Book Appointment 
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu

// Function to show calendar 
void showCalendar()
{
	// Print calendar 
	time_t current_time = time(NULL);
	struct tm* time_info = localtime(&current_time);
	if (!time_info) // check if time_info is null
	{
		printf("Error getting local time.\n");
		return;
	}

	int day = time_info->tm_mday;
	int month = time_info->tm_mon + NUMONE;
	int year = time_info->tm_year + STARTYEAR;

	// Print header 
	printf("\nToday's Date - %d/%d/%d\n\n", day, month, year);
	printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Calculate starting day and number of days in month
	time_info->tm_mday = NUMONE;
	time_info->tm_hour = EMPTYNUM;
	time_info->tm_min = EMPTYNUM;
	time_info->tm_sec = EMPTYNUM;
	time_info->tm_isdst = NEGATIVENUM;
	time_t start_of_month = mktime(time_info);
	time_info = localtime(&start_of_month);
	int start_day = time_info->tm_wday;
	int num_days = EMPTYNUM;
	while (time_info->tm_mon == month - NUMONE) {
		num_days++;
		start_of_month += 86400; // add one day (in seconds) to the timestamp
		time_info = localtime(&start_of_month);
	}

	// Print calendar 
	for (int i = EMPTYNUM; i < start_day; i++)
		printf("     ");
	for (int i = NUMONE; i <= num_days; i++)
	{
		printf("%4d ", i);
		if ((start_day + i) % DAYSINAWEEK == EMPTYNUM)
			printf("\n");
	}
	printf("\n");
}