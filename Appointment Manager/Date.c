#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <time.h> 

/*
GROUP 18 MEMBERS
-EHINOMHEN OSEZUAH
-YINUS ALAMUTU
-THE PROJECT ON THE HAIR SALON APPOINTMENT MANAGER
*/

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
	int month = time_info->tm_mon + 1;
	int year = time_info->tm_year + 1900;

	// Print header 
	printf("\nCalendar - %d/%d/%d\n\n", day, month, year);
	printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Calculate starting day and number of days in month
	time_info->tm_mday = 1;
	time_info->tm_hour = 0;
	time_info->tm_min = 0;
	time_info->tm_sec = 0;
	time_info->tm_isdst = -1;
	time_t start_of_month = mktime(time_info);
	time_info = localtime(&start_of_month);
	int start_day = time_info->tm_wday;
	int num_days = 0;
	while (time_info->tm_mon == month - 1) {
		num_days++;
		start_of_month += 86400; // add one day (in seconds) to the timestamp
		time_info = localtime(&start_of_month);
	}

	// Print calendar 
	for (int i = 0; i < start_day; i++)
		printf("     ");
	for (int i = 1; i <= num_days; i++)
	{
		printf("%4d ", i);
		if ((start_day + i) % 7 == 0)
			printf("\n");
	}
	printf("\n");
}