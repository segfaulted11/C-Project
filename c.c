#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step - 1 ()

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
struct Dorm d[100];//array of structures. this array contains 100 structure instances as its element. 

// Count variable (tracks number of students entered)
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

// step - 4

/* Goal ->
Let the user:

enter student info
store it in the array of structure
increase count

Basically: “save new record”

What does your add() function do? => “It takes user input and stores it into an array of structures, which acts as a temporary database.”

Step 1 → create database
Step 4 → insert data into database
*/

void add()
{
    printf("\n--- Add Student ---\n");

//  d[count]  Means: “store data in next empty slot”
// If count = 0 → goes to d[0]
// If count = 1 → goes to d[1]

    printf("Enter Student ID: ");
    scanf("%d", &d[count].studentID);
    printf("Enter Student Name: ");
    scanf("%s", d[count].name);
    printf("Enter Room Number: ");
    scanf("%d", &d[count].roomNumber);
    printf("Enter Check In Date: ");
    scanf("%s", d[count].checkInDate);
    printf("Enter Payment Status: ");
    scanf("%s", d[count].paymentStatus);

    count++; // 'count' tracks how many records are currently stored and ensures new data is added to the correct index in the array. the value of 'count' inceases by 1, everytime the 'add()' function is called. 

    printf("\nStudent added successfully!\n");
}


//main function
int main()
{
    int choice;

    login(); // step-2

    // step -3 (Menu System)

    // keeps running and lets the user choose actions

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
            add();//step - 4, calling the add function. 
            break;
        case 2:
            printf("View funtion called\n"); // text placeholder for now, real function will be added later.
            break;
        case 3:
            printf("Search funtion called\n"); // text placeholder for now, real function will be added later.
            break;
        case 4:
            printf("Edit funtion called\n"); // text placeholder for now, real function will be added later.
            break;
        case 5:
            printf("Delete funtion called\n"); // text placeholder for now, real function will be added later.
            break;
        case 0:
            printf("Exiting the program\n"); // text placeholder for now, real function will be added later.
            break;
        default:
            printf("Invalid choice! pls choose anything from 0-5\n");
        }
    } while (choice != 0); // keep showing menu until user chooses exit

    return 0;
}