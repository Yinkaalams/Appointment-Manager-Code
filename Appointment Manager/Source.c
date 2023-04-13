#define _CRT_SECURE_NO_WARNINGS
#include "Appointment.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/*
GROUP 18 MEMBERS
-EHINOMHEN OSEZUAH
-YINUS ALAMUTU
-THE PROJECT ON THE HAIR SALON APPOINTMENT MANAGER
*/

// Main function 
int main()
{
	int choice;
	do
	{
		choice = showMenu();
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
		case 9:
			saveAppointments();
			break;
		case 10:
			loadAppointments();
			break;
		case 0:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid option\n");
			break;
		}
	} while (choice != 0);

	return 0;
}