#pragma once
#include "Date.h"
#define SIZE_OF_THE_SERVICE_CUSTOMER_WANTS 200
#define TIME_CUSTOMER_CHOOSES_TO_ARRIVE 30
#define NEGATIVENUM -1
#define EMPTYNUM 0
#define NUMONE 1
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
// Appointment Interface
// Structure to store appointment 
typedef struct appointment
{
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	DATE date;
	char time[TIME_CUSTOMER_CHOOSES_TO_ARRIVE];
}APPOINTMENT;

// Array to store appointments 
APPOINTMENT appointments[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
int total_appointments;

void printmenu(void);
void enterAppointment();

void deleteAppointment();
void updateAppointment();

void displayAppointment();
void displayRangeAppointments();

void displayAllAppointments();
void searchAppointment();

void saveAppointments();
void loadAppointments();
int showMenu();




