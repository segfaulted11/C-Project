#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure (Blueprint of one record)
struct Dorm
{
    int studentID;
    char name[50];
    int roomNumber;
    char checkInDate[20];
    char paymentStatus[20]; // Paid / Unpaid
};

// Array of structures (acts like database)
struct Dorm d[100];

// Count variable (tracks number of records)
int count = 0;

// step -2 (Login system)
void login()
{
    char userName[20];
    char passWord[20];
    printf("Enter your Username : ");
    scanf("%s", userName);
    printf("Enter your password : ");
    scanf("%s", passWord);

    if (strcmp(userName, "a") == 0 && strcmp(passWord, "23") == 0)
    {
        printf("Log In Succesful!\n");
    }
    else
    {
        printf("Log In failed\n");
        printf("Exiting program...\n");
        exit(0);
    }
    /*
    strcmp() → compares strings
    == 0 → means strings are equal
    != 0 -> mean they r not equal
    exit(0) → force stop program
    */
}

int main()
{
    int choice;

    login(); // step-2

    // step -3 (Menu System)

    //keeps running and lets the user choose actions

    printf("\n====== Dorm Room Management System ======\n");
    printf("Enter 1 to add students\n");
    printf("Enter 2 to view students\n");
    printf("Enter 3 to search students\n");
    printf("Enter 4 to edit students\n");
    printf("Enter 5 to delete students\n");
    printf("Enter 6 to exit\n");
    do
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Add funtion called\n");//text placeholder for now, real function will be added later.
            break;
        case 2:
            printf("View funtion called\n");//text placeholder for now, real function will be added later.
            break;
        case 3:
            printf("Search funtion called\n");//text placeholder for now, real function will be added later.
            break;
        case 4:
            printf("Edit funtion called\n");//text placeholder for now, real function will be added later.
            break;
        case 5:
            printf("Delete funtion called\n");//text placeholder for now, real function will be added later.
            break;
        case 0:
            printf("Exiting the program\n");//text placeholder for now, real function will be added later.
            break;
        default:
            printf("Invalid choice! pls choose anything from 0-5\n");
        }
    }while(choice != 0);//keep showing menu until user chooses exit

    return 0;
}