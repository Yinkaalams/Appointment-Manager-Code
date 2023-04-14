#define _CRT_SECURE_NO_WARNINGS
#include "Printmenu.h"
#include "Utils.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXNUM 100
#define NUMONE 1
#define EMPTYNUM 0
#define NUMTWO 2
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
//Print Menu Implementation
void printmenu(void)
{
	// Display menu 
	printf("\n");
	printf("Appointment Manager\n");
	printf("============\n");
	printf("1. Enter new appointment\n");
	printf("2. Delete existing appointment\n");
	printf("3. Update existing appointment\n");
	printf("4. Display single appointment\n");
	printf("5. Display range of appointments\n");
	printf("6. Display all appointments\n");
	printf("7. Search for appointment\n");
	printf("8. Show Earliest Date For Appointment and Days In the Month\n");
	printf("0. Exit\n");
	printf("Enter your choice: ");
}

// Function to show menu 
int showMenuandGetinput(void)
{
    int choice = EMPTYNUM;
    char input[MAXNUM];
    int input_length = EMPTYNUM;

    do {
        printmenu();
        fgets(input, sizeof(input), stdin);
        removeTrailingNewline(input);
        input_length = strlen(input);
        if (input_length == NUMONE && input[EMPTYNUM] >= '0' && input[EMPTYNUM] <= '8') {
            choice = input[EMPTYNUM] - '0';
            break;
        }
        else {
            printf("Invalid option\n");
        }
    } while (NUMONE);

    return choice;
}