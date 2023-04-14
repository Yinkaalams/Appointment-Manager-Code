#define _CRT_SECURE_NO_WARNINGS
#include "Appointment.h"
#include "Date.h"
#include "Utils.h"
#include "Printmenu.h"
#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h> 
#include <string.h> 
//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
//Program to be for an Appointment Manager 
// Main function 
int main(void)
{
    loadAppointments();
    int done = EMPTYNUM;
    char input[MAXNUM];
    int input_length = EMPTYNUM;
    int choice = EMPTYNUM;
    int menuShown = EMPTYNUM; 

    while (!done)
    {
        if (menuShown == EMPTYNUM) { // if menu is not yet printed 
            printmenu();
            menuShown = NUMONE; //Menu already printed
        }

        fgets(input, sizeof(input), stdin);
        removeTrailingNewline(input);
        input_length = (int)strlen(input);

        if (input_length == NUMONE && input[EMPTYNUM] >= '0' && input[EMPTYNUM] <= '8')
        {
            choice = input[EMPTYNUM] - '0';
            switch (choice)
            {
            case 1:
                enterAppointment();
                menuShown = EMPTYNUM; // to print menu again after invalid input
                break;
            case 2:
                deleteAppointment();
                menuShown = EMPTYNUM;
                break;
            case 3:
                updateAppointment();
                menuShown = EMPTYNUM;
                break;
            case 4:
                displayAppointment();
                menuShown = EMPTYNUM;
                break;
            case 5:
                displayRangeAppointments();
                menuShown = EMPTYNUM;
                break;
            case 6:
                displayAllAppointments();
                menuShown = EMPTYNUM;
                break;
            case 7:
                searchAppointment();
                menuShown = EMPTYNUM;
                break;
            case 8:
                showEarliestDate();
                menuShown = EMPTYNUM;
                break;
            case 0:
                printf("Exiting....\n");
                done = NUMONE;
                break;
            default:
                printmenu();
                break;
            }
        }
        if (choice == EMPTYNUM)
        {
            printf("You have entered a wrong input\n");
            menuShown = EMPTYNUM;

        }
    }

    saveAppointments();
    return 0;
}