#define _CRT_SECURE_NO_WARNINGS
#include "Appointment.h"
#include "Printmenu.h"
#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
// Appointment Functions Implementation
// Function to set appointment 
void setDay(int index, int day) {
	appointments[index].date.day = day;
}

void setMonth(int index, int month) {
	appointments[index].date.month = month;
}

void setYear(int index, int year) {
	appointments[index].date.year = year;
}

// Getter functions for date for appointment
int getDay(int index) {
	return appointments[index].date.day;
}

int getMonth(int index) {
	return appointments[index].date.month;
}

int getYear(int index) {
	return appointments[index].date.year;
}

void setAppointment(char* description, int day, int month, int year, char* time)
{
	// Set appointment 
	strcpy(appointments[total_appointments].description, description);
	appointments[total_appointments].date.day = day;
	appointments[total_appointments].date.month = month;
	appointments[total_appointments].date.year = year;
	strcpy(appointments[total_appointments].time, time);
}
void setDescription(int index, char description[]) {
	strcpy(appointments[index].description, description);
}

// Function to get appointment description 
char* getDescription(int index)
{
	return appointments[index].description;
}

// Function to get appointment date 
DATE getDate(int index)
{
	return appointments[index].date;
}

// Function to get appointment time 
char* getTime(int index)
{
	return appointments[index].time;
}
// Setter function for time
void setTime(int index, char time[]) {
	strcpy(appointments[index].time, time);
}

// Function to enter appointment 
void enterAppointment()
{
	// Get user input for appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter your appointment details\n");
	printf("Description: ");
	if ((scanf("%s", description) > 0))
	{
		int day, month, year;
		printf("Enter date\n");
		printf("Day: ");
		if ((scanf("%d", &day) == 1))
		{
			printf("Month: ");
			if ((scanf("%d", &month) == 1))
			{
				printf("Year: ");
				if ((scanf("%d", &year) == 1))
				{
					char* time = (char*)malloc(10 * sizeof(char));
					if (time == NULL) // Checking if allocation failed
					{
						printf("Error: Memory allocation failed\n");
						return;
					}

					printf("Time: ");
					if ((scanf("%s", time) > 0))
					{
						// Set appointment 
						setAppointment(description, day, month, year, time);

						// Increment total appointments 
						total_appointments++;

						printf("Appointment Successfully Booked\n");

						free(time); // Free allocated memory
					}
				}
			}
		}
	}
}

// Function to delete appointment 
void deleteAppointment()
{
	// Get user input for deleting appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to delete: ");
	if ((scanf("%s", description) > 0))
	{
		description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS - NUMONE] = '\0';
		// Search for appointment 
		int index = NEGATIVENUM;
		for (int i = EMPTYNUM; i < total_appointments; i++)
		{
			if (strcmp(description, getDescription(i)) == EMPTYNUM)
			{
				index = i;
				break;
			}
		}

		// If appointment is found 
		if (index != NEGATIVENUM)
		{
			// Shift remaining appointments one step forward 
			for (int i = index; i < total_appointments - NUMONE; i++)
				appointments[i] = appointments[i + NUMONE];

			// Decrement total appointments 
			total_appointments--;

			// Open the file for writing in binary mode
			FILE* fp = fopen("appointments.dat", "wb");
			if (fp == NULL)
			{
				printf("Error opening file\n");
				return;
			}

			// Write the updated appointments array to the file
			fwrite(appointments, sizeof(APPOINTMENT), total_appointments, fp);

			// Close the file
			fclose(fp);

			printf("Appointment deleted successfully\n");
		}

		// If appointment not found 
		else
			printf("Appointment not found\n");
	}
}

// Function to update appointment 
void updateAppointment()
{
	// Get user input for updating appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to update: ");
	if ((scanf("%s", description) > 0))
	{
		description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS - NUMONE] = '\0';
		// Search for appointment 
		int index = NEGATIVENUM;
		for (int i = EMPTYNUM; i < total_appointments; i++)
			if (strcmp(description, getDescription(i)) == EMPTYNUM)
				index = i;

		// If appointment is found 
		if (index != NEGATIVENUM)
		{
			// Get user input for appointment 
			printf("Enter your appointment details\n");
			printf("Description: ");
			char* customerChoice = getDescription(index);
			if ((scanf("%s", customerChoice) > 0))
			{
				printf("Enter date\n");
				printf("Day: ");
				int customerDate = getDay(index);
				if ((scanf("%d", &customerDate) == 1))
				{
					printf("Month: ");
					int customerMonth = getMonth(index);
					if ((scanf("%d", &customerMonth) == 1))
					{
						printf("Year: ");
						int customerYear = getYear(index);
						if ((scanf("%d", &customerYear) == 1))
						{
							printf("Time: ");
							char* customerTime = getTime(index);
							if ((scanf("%s", customerTime) > 0))
							{
								printf("Appointment updated successfully\n");
							}
						}
					}
				}
			}
		}

		// If appointment not found 
		else
			printf("Appointment not found\n");
	}
}

// Function to display single appointment 
void displayAppointment()
{
	// Get user input for displaying appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to display: ");
	if ((scanf("%s", description) > 0))
	{
		description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS - NUMONE] = '\0';
		// Search for appointment 
		int index = NEGATIVENUM;
		for (int i = EMPTYNUM; i < total_appointments; i++)
			if (strcmp(description, getDescription(i)) == EMPTYNUM)
				index = i;

		// If appointment is found 
		if (index != NEGATIVENUM)
		{
			printf("Your appointment is\n");
			printf("Description: %s\n", getDescription(index));
			DATE date = getDate(index);
			printf("Date: %d/%d/%d\n", date.day, date.month, date.year);
			printf("Time: %s\n", getTime(index));
		}

		// If appointment not found 
		else
			printf("Appointment not found\n");
	}
}

// Function to display range of appointments 
void displayRangeAppointments()
{
	// Get user input for range 
	DATE start = { EMPTYNUM };
	DATE end = { EMPTYNUM };
	printf("Enter start date\n");

	printf("Day: ");
	int StartDay_Choice = start.day;
	if ((scanf("%d", &StartDay_Choice) == 1))
	{
		printf("Month: ");
		int StartMonth_Choice = start.month;
		if ((scanf("%d", &StartMonth_Choice) == 1))
		{
			printf("Year: ");
			int StartYear_Choice = start.year;
			if ((scanf("%d", &StartYear_Choice) == 1))
			{
				printf("Enter end date\n");

				printf("Day: ");
				int EndDay_Choice = end.day;
				if ((scanf("%d", &EndDay_Choice) == 1))
				{
					printf("Month: ");
					int EndMonth_Choice = end.month;
					if ((scanf("%d", &EndMonth_Choice) == 1))
					{
						printf("Year: ");
						int EndYear_Choice = end.year;
						if ((scanf("%d", &EndYear_Choice) == 1))
						{
							// Display appointments in the range 
							int found = EMPTYNUM;
							for (int i = EMPTYNUM; i < total_appointments; i++)
							{
								// Compare dates 
								if ((getYear(i) > start.year &&
									getYear(i) < end.year) ||

									((getYear(i) == start.year ||
										getYear(i) == end.year) &&

										(getMonth(i) > start.month &&
											getMonth(i) < end.month)) ||

									((getYear(i) == start.year ||
										getYear(i) == end.year) &&

										(getMonth(i) == start.month ||
											getMonth(i) == end.month) &&

										(getDay(i) >= start.day &&
											getDay(i) <= end.day)))
								{
									found = NUMONE;
									printf("Your appointment is\n");
									printf("Description: %s\n", getDescription(i));
									printf("Date: %d / %d /%d \n", getDay(i),
										getMonth(i),
										getYear(i));
									printf("Time: %s\n", getTime(i));
								}
							}

							// If appointment not found 
							if (!found)
								printf("No appointment found in the range\n");
						}
					}
				}
			}
		}
	}
}


// Function to display all appointments 
void displayAllAppointments()
{
	// Display all appointments 
	if (total_appointments == EMPTYNUM)
		printf("No appointments found\n");
	else
		for (int i = EMPTYNUM; i < total_appointments; i++)
		{
			printf("Your appointment is\n");
			printf("Description: %s\n", getDescription(i));

			// Check for invalid date
			if (getDay(i) == EMPTYNUM ||
				getMonth(i) == EMPTYNUM ||
				getYear(i) == EMPTYNUM) {
				printf("Date: Invalid date\n");
			}
			else {
				printf("Date: %d/%d/%d\n", getDay(i),
					getMonth(i),
					getYear(i));
			}

			printf("Time: %s\n", getTime(i));
		}
}

// Function to search appointment 
void searchAppointment()
{
	// Get user input for searching appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to search: ");
	if ((scanf("%s", description) > 0))
	{
		description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS - NUMONE] = '\0';
		// Search for appointment 
		int found = EMPTYNUM;
		for (int i = EMPTYNUM; i < total_appointments; i++)
			if (strcmp(description, getDescription(i)) == EMPTYNUM)
			{
				found = NUMONE;
				printf("Your appointment is\n");
				printf("Description: %s\n", getDescription(i));
				printf("Date: %d/%d/%d\n", getDay(i),
					getMonth(i),
					getYear(i));
				printf("Time: %s\n", getTime(i));
			}

		// If appointment not found 
		if (!found)
			printf("Appointment not found\n");
	}
}

// Function to save appointments to disk 
void saveAppointments()
{
	// Open file 
	FILE* fp;
	fp = fopen("appointments.txt", "w");

	// Save appointments to file 
	for (int i = EMPTYNUM; i < total_appointments; i++) {
		fprintf(fp, "%s %d %d %d %s\n", getDescription(i),
			getDay(i),
			getMonth(i),
			getYear(i),
			getTime(i));
	}

	// Close file 
	fclose(fp);
}

// Function to load appointments from disk 
void loadAppointments()
{
	FILE* fp = fopen("appointments.dat", "rb");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	total_appointments = EMPTYNUM;
	while (fread(&appointments[total_appointments], sizeof(APPOINTMENT), NUMONE, fp) == NUMONE)
	{
		total_appointments++;
	}

	fclose(fp);
}

