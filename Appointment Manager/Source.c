#define _CRT_SECURE_NO_WARNINGS
#include "PrintMenu.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

// Structure to store date 
struct date
{
	int day;
	int month;
	int year;
};

// Structure to store appointment 
struct appointment
{
	char description[50];
	struct date date;
	char time[6];
};

// Array to store appointments 
struct appointment appointments[100];
int total_appointments = 0;

// Function to enter appointment 
void enterAppointment()
{
	// Get user input for appointment 
	printf("Enter your appointment details\n");
	printf("Description: ");
	scanf("%s", appointments[total_appointments].description);

	printf("Enter date\n");
	printf("Day: ");
	scanf("%d", &appointments[total_appointments].date.day);
	printf("Month: ");
	scanf("%d", &appointments[total_appointments].date.month);
	printf("Year: ");
	scanf("%d", &appointments[total_appointments].date.year);

	printf("Time: ");
	scanf("%s", appointments[total_appointments].time);

	// Increment total appointments 
	total_appointments++;
}

// Function to delete appointment 
void deleteAppointment()
{
	// Get user input for deleting appointment 
	char description[50];
	printf("Enter description for appointment to delete: ");
	scanf("%s", description);

	// Search for appointment 
	int index = -1;
	for (int i = 0; i < total_appointments; i++)
		if (strcmp(description, appointments[i].description) == 0)
			index = i;

	// If appointment is found 
	if (index != -1)
	{
		// Shift remaining appointments one step back 
		for (int i = index; i < total_appointments - 1; i++)
			appointments[i] = appointments[i + 1];

		// Decrement total appointments 
		total_appointments--;
		printf("Appointment deleted successfully\n");
	}

	// If appointment not found 
	else
		printf("Appointment not found\n");
}

// Function to update appointment 
void updateAppointment()
{
	// Get user input for updating appointment 
	char description[50];
	printf("Enter description for appointment to update: ");
	scanf("%s", description);

	// Search for appointment 
	int index = -1;
	for (int i = 0; i < total_appointments; i++)
		if (strcmp(description, appointments[i].description) == 0)
			index = i;

	// If appointment is found 
	if (index != -1)
	{
		// Get user input for appointment 
		printf("Enter your appointment details\n");
		printf("Description: ");
		scanf("%s", appointments[index].description);

		printf("Enter date\n");
		printf("Day: ");
		scanf("%d", &appointments[index].date.day);
		printf("Month: ");
		scanf("%d", &appointments[index].date.month);
		printf("Year: ");
		scanf("%d", &appointments[index].date.year);

		printf("Time: ");
		scanf("%s", appointments[index].time);

		printf("Appointment updated successfully\n");
	}

	// If appointment not found 
	else
		printf("Appointment not found\n");
}

// Function to display single appointment 
void displayAppointment()
{
	// Get user input for displaying appointment 
	char description[50];
	printf("Enter description for appointment to display: ");
	scanf("%s", description);

	// Search for appointment 
	int index = -1;
	for (int i = 0; i < total_appointments; i++)
		if (strcmp(description, appointments[i].description) == 0)
			index = i;

	// If appointment is found 
	if (index != -1)
	{
		printf("Your appointment is\n");
		printf("Description: %s\n", appointments[index].description);
		printf("Date: %d/%d/%d\n", appointments[index].date.day,
			appointments[index].date.month,
			appointments[index].date.year);
		printf("Time: %s\n", appointments[index].time);
	}

	// If appointment not found 
	else
		printf("Appointment not found\n");
}

// Function to display range of appointments 
void displayRangeAppointments()
{
	// Get user input for range 
	struct date start, end;
	printf("Enter start date\n");
	printf("Day: ");
	scanf("%d", &start.day);
	printf("Month: ");
	scanf("%d", &start.month);
	printf("Year: ");
	scanf("%d", &start.year);

	printf("Enter end date\n");
	printf("Day: ");
	scanf("%d", &end.day);
	printf("Month: ");
	scanf("%d", &end.month);
	printf("Year: ");
	scanf("%d", &end.year);

	// Display appointments in the range 
	int found = 0;
	for (int i = 0; i < total_appointments; i++)
	{
		// Compare dates 
		if ((appointments[i].date.year > start.year &&
			appointments[i].date.year < end.year) ||

			((appointments[i].date.year == start.year ||
				appointments[i].date.year == end.year) &&

				(appointments[i].date.month > start.month &&
					appointments[i].date.month < end.month)) ||

			((appointments[i].date.year == start.year ||
				appointments[i].date.year == end.year) &&

				(appointments[i].date.month == start.month ||
					appointments[i].date.month == end.month) &&

				(appointments[i].date.day >= start.day &&
					appointments[i].date.day <= end.day)))
		{
			found = 1;
			printf("Your appointment is\n");
			printf("Description: %s\n", appointments[i].description);
			printf("Date: %d/%d/%d\n", appointments[i].date.day,
				appointments[i].date.month,
				appointments[i].date.year);
			printf("Time: %s\n", appointments[i].time);
		}
	}

	// If appointment not found 
	if (!found)
		printf("No appointment found in the range\n");
}

// Function to display all appointments 
void displayAllAppointments()
{
	// Display all appointments 
	if (total_appointments == 0)
		printf("No appointments found\n");
	else
		for (int i = 0; i < total_appointments; i++)
		{
			printf("Your appointment is\n");
			printf("Description: %s\n", appointments[i].description);
			printf("Date: %d/%d/%d\n", appointments[i].date.day,
				appointments[i].date.month,
				appointments[i].date.year);
			printf("Time: %s\n", appointments[i].time);
		}
}

// Function to search appointment 
void searchAppointment()
{
	// Get user input for searching appointment 
	char description[50];
	printf("Enter description for appointment to search: ");
	scanf("%s", description);

	// Search for appointment 
	int found = 0;
	for (int i = 0; i < total_appointments; i++)
		if (strcmp(description, appointments[i].description) == 0)
		{
			found = 1;
			printf("Your appointment is\n");
			printf("Description: %s\n", appointments[i].description);
			printf("Date: %d/%d/%d\n", appointments[i].date.day,
				appointments[i].date.month,
				appointments[i].date.year);
			printf("Time: %s\n", appointments[i].time);
		}

	// If appointment not found 
	if (!found)
		printf("Appointment not found\n");
}

// Function to save appointments to disk 
void saveAppointments()
{
	// Open file 
	FILE* fp;
	fp = fopen("appointments.txt", "w");

	// Save appointments to file 
	for (int i = 0; i < total_appointments; i++)
		fprintf(fp, "%s %d %d %d %s\n", appointments[i].description,
			appointments[i].date.day,
			appointments[i].date.month,
			appointments[i].date.year,
			appointments[i].time);

	// Close file 
	fclose(fp);
	printf("Appointments saved successfully\n");
}

// Function to load appointments from disk 
void loadAppointments()
{
	// Open file 
	FILE* fp;
	fp = fopen("appointments.txt", "r");

	// Load appointments from file 
	while (fscanf(fp, "%s %d %d %d %s\n", appointments[total_appointments].description,
		&appointments[total_appointments].date.day,
		&appointments[total_appointments].date.month,
		&appointments[total_appointments].date.year,
		appointments[total_appointments].time) != EOF)
		total_appointments++;

	// Close file 
	fclose(fp);
	printf("Appointments loaded successfully\n");
}

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


// Function to show menu 
int showMenu()
{
	printmenu();

	// Get user input 
	int choice;
	scanf("%d", &choice);

	// Return user input 
	return choice;
}

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