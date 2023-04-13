#define _CRT_SECURE_NO_WARNINGS
#include "Appointment.h"
#include "Date.h"
#include <stdio.h>
#include <string.h>
/*
GROUP 18 MEMBERS
-EHINOMHEN OSEZUAH
-YINUS ALAMUTU
-THE PROJECT ON THE HAIR SALON APPOINTMENT MANAGER
*/


void printmenu(void)
{
	// Display menu 
	printf("\n");
	printf("Calendar App\n");
	printf("============\n");
	printf("1. Enter new appointment\n");
	printf("2. Delete existing appointment\n");
	printf("3. Update existing appointment\n");
	printf("4. Display single appointment\n");
	printf("5. Display range of appointments\n");
	printf("6. Display all appointments\n");
	printf("7. Search for appointment\n");
	printf("8. Show calendar\n");
	printf("9. Save appointments to disk\n");
	printf("10. Load appointments from disk\n");
	printf("0. Exit\n");
	printf("Enter your choice: \n");
}

// Function to enter appointment 
void enterAppointment()
{
	// Get user input for appointment 
	printf("Enter your appointment details\n");
	printf("Description: ");
	char* CustomersChoice = appointments[total_appointments].description; 
	fgets(CustomersChoice, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

	printf("Enter date\n");
	printf("Day: ");
	int DayCustomerPicks = appointments[total_appointments].date.day;
	scanf("%d", &DayCustomerPicks);

	printf("Month: ");
	int MonthCustomerPicks = appointments[total_appointments].date.month;
	scanf("%d", &MonthCustomerPicks);

	printf("Year: ");
	int YearCustomerPicks = appointments[total_appointments].date.year;
	scanf("%d", &YearCustomerPicks);

	printf("Time: ");
	char* TimeCustomerPicks = appointments[total_appointments].time;
	fgets(TimeCustomerPicks, TIME_CUSTOMER_CHOOSES_TO_ARRIVE, stdin);

	// Increment total appointments 
	total_appointments++;
}

// Function to delete appointment 
void deleteAppointment()
{
	// Get user input for deleting appointment 
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to delete: ");
	fgets(description, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

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
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to update: ");
	fgets(description, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

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
		char* CustomerChoice = appointments[index].description;
		fgets(CustomerChoice, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

		printf("Enter date\n");
		printf("Day: ");
		int CustomerDate = appointments[index].date.day;
		scanf("%d", &CustomerDate);

		printf("Month: ");
		int CustomerMonth = appointments[index].date.month;
		scanf("%d", &CustomerMonth);

		printf("Year: ");
		int CustomerYear = appointments[index].date.year;
		scanf("%d", &CustomerYear);

		printf("Time: \n");
		char* CustomerTime = appointments[index].time;
		fgets(CustomerTime, TIME_CUSTOMER_CHOOSES_TO_ARRIVE, stdin);

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
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to display: ");
	fgets(description, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

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
	DATE start = { 0 };
	DATE end = { 0 };
	printf("Enter start date\n");

	printf("Day: ");
	int StartDay_Choice = start.day;
	scanf("%d", &StartDay_Choice);

	printf("Month: ");
	int StartMonth_Choice = start.month;
	scanf("%d", &StartMonth_Choice);

	printf("Year: ");
	int StartYear_Choice = start.year;
	scanf("%d", &StartYear_Choice);

	printf("Enter end date\n");

	printf("Day: ");
	int EndDay_Choice = end.day;
	scanf("%d", &EndDay_Choice);

	printf("Month: ");
	int EndMonth_Choice = end.month;
	scanf("%d", &EndMonth_Choice);

	printf("Year: ");
	int EndYear_Choice = end.year;
	scanf("%d", &EndYear_Choice);

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
	char description[SIZE_OF_THE_SERVICE_CUSTOMER_WANTS];
	printf("Enter description for appointment to search: ");
	fgets(description, SIZE_OF_THE_SERVICE_CUSTOMER_WANTS, stdin);

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