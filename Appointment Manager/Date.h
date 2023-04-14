#pragma once

//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
// Date Interface

// Structure to store date 
#define NUMONE 1
#define EMPTYNUM 0
#define DAYSINAWEEK 7
#define NEGATIVENUM -1
#define STARTYEAR 1900
#define NUMBEROFSECONDSINADAY 86400
typedef struct date
{
	int day;
	int month;
	int year;
}DATE;

void showEarliestDate();
