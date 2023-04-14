#define _CRT_SECURE_NO_WARNINGS
#include "Appointment.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
//Program to be for an Appointment Manager 
// Main function 
int main(void)
{
	loadAppointments();
	int choice;
	do
	{
		choice = showMenuandGetinput();
		switch (choice)
		{
		case 1:
			enterAppointment();
			break;
		case 2:
			deleteAppointment();
			break;
		case 3:
			updateAppointment();
			break;
		case 4:
			displayAppointment();
			break;
		case 5:
			displayRangeAppointments();
			break;
		case 6:
			displayAllAppointments();
			break;
		case 7:
			searchAppointment();
			break;
		case 8:
			showCalendar();
			break;
		case 0:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid option\n");
			break;
		}
	} while (choice != EMPTYNUM);
          saveAppointments();
	return 0;
}